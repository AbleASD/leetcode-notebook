#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &chess)
    {
        int n = chess.size();
        vector<int> sumadd(n + 1, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += chess[i];
            sumadd[i + 1] = sum;
        }
        int ret = INT_MAX;
        for (int i = 0; i <= n - sum; ++i) {
            ret = min(ret, sum - (sumadd[i + sum] - sumadd[i]));
        }
        return ret;
    }
};

int main() {
    Solution slt;
    vector<int> chess = {1, 0, 0, 1, 1, 1};
    cout << slt.minSwaps(chess);
}