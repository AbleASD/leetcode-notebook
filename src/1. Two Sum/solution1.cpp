/*
 * @Author: Able 
 * @Date: 2022-07-02 20:45:35 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-02 21:52:11
 * 
 * @link https://leetcode.cn/problems/two-sum/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(target - nums[i]) != um.end()) {
                return {i, um[target - nums[i]]};
            }
            else {
                um[nums[i]] = i; 
            }
        }
        return {};
    }
};
