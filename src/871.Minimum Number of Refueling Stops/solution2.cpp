/*
 * @Author: Able 
 * @Date: 2022-07-02 20:45:35 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-02 21:15:12
 * 
 * @link https://leetcode.cn/problems/minimum-number-of-refueling-stops/ @endlink
 */


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// dynamic programing
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<int> dp(n + 1); // 加油 n 次可到达的最远距离
        dp[0] = startFuel;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (dp[j] >= stations[j][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        
        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) {
                return i;
            }
        }
        return - 1;
    }
};

int main() {
    Solution slt;
    int target = 100, startFuel = 1;
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    slt.minRefuelStops(target, startFuel, stations);
    return 0;
}