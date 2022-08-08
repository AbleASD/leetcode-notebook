/*
 * @Author: Able
 * @Date: 2022-07-22 21:48:36
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-22 21:49:07
 * @link https://leetcode.cn/problems/the-latest-time-to-catch-a-bus/submissions/ @endlink
 */
#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int j = 0, c;
        for (int t: buses) {
            // c == 0 说明当前车辆已满
            // j == passengers.size() 说明乘客已全部上车
            // passengers[j] > t 说明此乘客错过当前车辆发车时间
            for (c = capacity; c && j < passengers.size() && passengers[j] <= t; ++j) {
                --c;
            }
        }
        --j;
        // 如果最后一辆车没有坐满，则搜索最后一辆车的乘坐时间
        // 如果最后一辆车坐满了，则找到最后上车的乘客
        int ans = c? buses.back(): passengers[j];
        // 上一个乘客和当前乘客之间存在空隙，则插入空袭
        while (j >= 0 && passengers[j--] == ans) --ans;
        return ans;
    }
};

int main()
{
    string ret = "asd";
    char c = 'f';
    ret.push_back(c);
    cout << ret;
    return 0;
}