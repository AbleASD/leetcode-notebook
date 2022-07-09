/*
 * @Author: Able 
 * @Date: 2022-07-04 21:28:40 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-04 21:37:44
 * @link https://leetcode.cn/problems/minimum-absolute-difference/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        int rm = INT_MAX;
        vector<vector<int>> res;
        for (int i = 0; i < n - 1; ++i) {
            int tmp = arr[i + 1] - arr[i];
            if (tmp < rm) {
                rm = tmp;
                res = {{arr[i], arr[i + 1]}};
            }
            else if (tmp == rm){
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};

int main() {
    Solution slt;
    vector<int> arr = {4,2,1,3};
    slt.minimumAbsDifference(arr);
    return 0;
}