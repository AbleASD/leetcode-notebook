#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int buildTransferStation(vector<vector<int>> &area)
    {
        int n = area.size(), m = area[0].size();
        vector<int> vx;
        vector<int> vy;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (area[i][j]) {
                    vx.push_back(i);
                    vy.push_back(j);
                }
            }
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        int len = vx.size();
        int x = vx[len / 2];
        int y = vy[len / 2];

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (area[i][j]) {
                    ret += (abs(x - i) + abs(y - j));
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> area = { { 0, 1, 0, 0, 0 }, { 0, 0, 0, 0, 1 }, { 0, 0, 1, 0, 0 }};
    Solution slt;
    cout << slt.buildTransferStation(area);
    return 0;
}