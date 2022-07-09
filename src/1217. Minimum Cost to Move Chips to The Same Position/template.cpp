#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // 奇偶统计
    int minCostToMoveChips(vector<int> &position)
    {
        int odd = 0, even = 0;
        for (int i = 0; i < position.size(); ++i)
        {
            if (position[i] & 1)
            {
                odd += 1;
            }
            else
            {
                even += 1;
            }
        }
        return min(odd, even);
    }
};

int main() {
    vector<int> position = {1, 2, 3};
    Solution slt;
    slt.minCostToMoveChips(position);
    return 0;
}