#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool canReceiveAllSignals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            if (a[0] < b[0]) {
                return true;
            } else if (a[0] == b[0] && a[1] <b[1]) {
                return true;
            }
            return false;
        });

        for (int i = 1; i < intervals.size(); ++i ) {
            if (intervals[i][0] <intervals[i - 1][1]) return false;
        }
        return true;
    }
};