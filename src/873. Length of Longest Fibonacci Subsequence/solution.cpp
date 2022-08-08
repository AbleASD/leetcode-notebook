#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        unordered_map<int, int> indexs;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            indexs[arr[i]] = i;
        }


        // arr[k] + arr[j] = arr[i] k < j < i
        // arr[k] < arr[j] < arr[i] => 2 * arr[j] > arr[i]

        // dp[j][i] = max(dp[k][j] + 1, 3)

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0 && 2 * arr[j] > arr[i]; --j) {
                int k = -1;
                if (indexs.count(arr[i] - arr[j])) {
                    k = indexs[arr[i] - arr[j]];
                }
                if (k >= 0) {
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution slt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << slt.lenLongestFibSubseq(arr);
    return 0;
}