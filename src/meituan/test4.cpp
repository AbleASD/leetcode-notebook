#include "bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, tmp;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }
    int ret = 0;

    sort(nums.begin(), nums.end());

    for (int j = 0; j < n; ++j) {
        for (int i = j + 1; i < n; ++i) {
            int sum = 3 * nums[j];
            for (int k = i + 1; k < n; ++k) {
                if (nums[k] + nums[i] == sum) {
                    ret++;
                } else if (nums[k] + nums[i] > sum) break;
            }
        }
    }
    cout << ret / 2 << endl;
    return 0;
}