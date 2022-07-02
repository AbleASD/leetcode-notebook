/*
 * @Author: Able 
 * @Date: 2022-07-02 20:45:35 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-02 20:56:13
 * 
 * @link https://leetcode.cn/problems/minimum-number-of-refueling-stops/ @endlink
 */


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// greedy + heap: complex O(n)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (target <= startFuel) return 0;
        priority_queue<int> pq;
        int n = stations.size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            while (startFuel < stations[i][0]) {
                if (pq.empty()) break;
                startFuel += pq.top();
                pq.pop();
                ret++;
                if (startFuel >= target) return ret;
            }
            if (startFuel >= stations[i][0])
                pq.emplace(stations[i][1]);
        }
        while (!pq.empty()) {
            if (startFuel >= target) return ret;
            startFuel += pq.top();
            pq.pop(); ret++;
        }
        return startFuel >= target ? ret: -1;
    }
};

int main() {
    Solution slt;
    int target = 100, startFuel = 1;
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    slt.minRefuelStops(target, startFuel, stations);
    return 0;
}