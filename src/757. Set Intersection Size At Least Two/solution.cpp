/*
 * @Author: Able
 * @Date: 2022-07-22 21:55:14
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-22 22:21:30
 * @link https://leetcode.cn/problems/set-intersection-size-at-least-two/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void recursion(vector<vector<int>> &intervals, vector<int> &counter, int pos, int val)
    {
        for (int i = pos; i >= 0; --i)
        {
            if (intervals[i][1] < val) {
                return;
            }
            counter[i]++;
        }
    }

    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b)
             {
            if (a[0] == b[0]) {
               return a[1] > b[1];
            }
            return a[0] < b[0]; });

        int n = intervals.size();
        vector<int> counter(n);
        int ret = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            for (int el = intervals[i][0], count = counter[i]; count < 2; ++count, ++el)
            {
                ret++;
                recursion(intervals, counter, i - 1, el);
            }
        }
        return ret;
    }
};

int main()
{
    Solution slt;
    vector<vector<int>> intervals = {{1, 3},
                                     {1, 4},
                                     {2, 5},
                                     {3, 5}};
    cout << slt.intersectionSizeTwo(intervals);
    return 0;
}