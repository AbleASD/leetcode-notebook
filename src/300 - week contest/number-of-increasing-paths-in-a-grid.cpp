/*
 * @Author: Able 
 * @Date: 2022-07-03 16:07:19 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-03 18:13:03
 * @link https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/ @endlink
 */


#include <bits/stdc++.h>
using namespace std;


// dynamic search, dfs
constexpr int mod = 1e9 + 7; 
const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    void add(int &x, int y) {
        x += y;
        if (x >= mod) x -= mod;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j] != 0) return;
        dp[i][j] = 1;
        int n = grid.size(), m = grid[0].size();
        auto check = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        for (auto &d: dirs) {
            if (check(i + d[0], j + d[1]) && grid[i][j] < grid[i + d[0]][j + d[1]]) {
                if (dp[i + d[0]][j + d[1]] == 0) dfs(grid, dp, i + d[0], j + d[1]);
                add(dp[i][j], dp[i + d[0]][j + d[1]]);
            }
        }
    }
    int countPaths(vector<vector<int>> &grid) {
        int ret = 0;
        int n = grid.size(), m = grid[0].size();   
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(grid, dp, i, j);
                add(ret, dp[i][j]);
            }
        }
        return ret;
    }    
};

int main() {
    Solution slt;
    vector<vector<int>> grid = {{1, 1}, {3, 4}};
    cout << slt.countPaths(grid);
}