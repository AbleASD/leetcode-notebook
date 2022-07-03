/*
 * @Author: Able 
 * @Date: 2022-07-03 15:43:21 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-03 16:03:29
 * @link https://leetcode.cn/problems/number-of-people-aware-of-a-secret/ @endlink 
 */


#include <bits/stdc++.h>
using namespace std;


constexpr int mod = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, 0); // the number of people who awareed the secret at n-st day.
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = max(i - forget + 1, 1); j <= i - delay; ++j) {
                dp[i] += dp[j];
                if (dp[i] >= mod) dp[i] -= mod;
            }
        }
        int ret = 0;
        for (int i = n; i >= n - forget + 1; --i) {
            ret += dp[i];
            if (ret >= mod) ret -= mod;
        }
        return ret;
    }
};

int main() {
    Solution slt;
    cout << slt.peopleAwareOfSecret(4, 1, 3);
}