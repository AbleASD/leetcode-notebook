/*
 * @Author: Abel Williams
 * @Date: 2023-03-11 04:24:36
 * @Last Modified by: Abel Williams
 * @Last Modified time: 2023-03-11 05:26:39
 * @line https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();

        // 邻接表
        vector<vector<int>> g(n);

        // 节点入度统计
        vector<int> inDegree(n);
        for (auto &edge : edges)
        {
            ++inDegree[edge[1]];
            g[edge[0]].push_back(edge[1]);
        }

        // 记录拓扑排序过程中遇到的节点数

        vector<array<int, 36>> f(n);
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (!inDegree[i])
            {
                q.push(i);
            }
        }

        // 如果存在环，那么环中节点无法入队
        // fount 不为 n 说明存在无法入队的节点
        int found = 0, ans = 0;
        while (!q.empty())
        {
            ++found;
            int front = q.front();
            q.pop();

            // 对应节点颜色值增加
            ++f[front][colors[front] - 'a'];

            if (g[front].empty()) {
                for (int c = 0; c < 26; ++c) {
                    ans = max(ans, f[front][c]);
                }
                continue;
            }
            // 枚举front 后继节点
            for (int v : g[front])
            {
                --inDegree[v];
                for (int c = 0; c < 26; ++c)
                {
                    f[v][c] = max(f[v][c], f[front][c]);
                }
                if (!inDegree[v])
                {
                    q.push(v);
                }
            }
        }

        if (found != n)
        {
            return -1;
        }
        return ans;
    }
};

int main(void)
{
    Solution slt;
    string colors = "iiiiii";
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    slt.largestPathValue(colors, edges);
    return 0;
}