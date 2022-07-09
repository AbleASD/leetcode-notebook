#include "bits/stdc++.h"
using namespace std;

// 没理解
class Solution
{
public:
    int minTransfers(vector<vector<int>> &distributions)
    {
        vector<int> door(12, 0);
        int n = distributions.size();

        for (auto & distribution: distributions) {
            door[distribution[0]] -= distribution[2];
            door[distribution[1]] += distribution[1];
        }
        return 0;
        // 贪心，非0元素一定成对出现， 集合划分，和为0的子集可以通过一次连通划分
        // n个节点通过n - 1条边连接，即交换 n-1次
        // 划分为k个集合则需要 n-k次调配

    }
};

int main() {
    return 0;
}

// class Solution
// {
// public:
//     int minTransfers(vector<vector<int>> &distributions)
//     {
//         vector<int> A(12), B;
//         for (auto &vec : distributions)
//             A[vec[0]] -= vec[2], A[vec[1]] += vec[2];
//         for (int x : A)
//             if (x)
//                 B.push_back(x);
//         int n = B.size();
//         vector<int> f(1 << n), g(1 << n);
//         for (int i = 0; i < (1 << n); i++)
//             for (int j = 0; j < n; j++)
//                 if (i >> j & 1)
//                     g[i] += B[j];
//         for (int i = 1; i < (1 << n); i++)
//             for (int j = i; j; j = (j - 1) & i)
//                 if (g[j] == 0)
//                     f[i] = max(f[i], f[i & (~j)] + 1);
//         return n - f[(1 << n) - 1];
//     }
// };