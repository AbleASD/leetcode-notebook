/*
 * @Author: Able 
 * @Date: 2022-07-02 20:45:35 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-02 22:03:35
 * 
 * @link https://leetcode.cn/problems/two-sum/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

// binary search
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int tmp = target - nums[i];
            int l = i + 1, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] == tmp) return vector<int>({i, mid});
                else if (nums[mid] < tmp) l = mid + 1; 
                else if (nums[mid] > tmp) r = mid;
            }
        }
        return vector<int>({});
    }
};

int main() {
    Solution slt;
    vector<int> nums = {3,2,4};
    slt.twoSum(nums, 6);
    return 0;
}