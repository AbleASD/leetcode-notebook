/*
 * @Author: Able
 * @Date: 2022-07-22 21:49:22
 * @Last Modified by:   Able
 * @Last Modified time: 2022-07-22 21:49:22
 * @link https://leetcode.cn/problems/minimum-sum-of-squared-difference/ @endlink
 */
#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        // x^2 - (x-1)^2 = 2 * x - 1
        // 当x != 0 时  单调递增，从最大的开始减少
        int n = nums1.size(), k = k1 + k2;

        long ans = 0, sum = 0;

        for (int i = 0; i < n; ++i) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            sum += nums1[i];
            ans += (long) nums1[i] * nums1[i];
        }

        if (sum < k) return 0;
        sort(nums1.begin(), nums1.end(), greater<>());
        nums1.push_back(0);

        for (int i =0;;i++) {
            long j = i + 1, v = nums1[i], c = j * (v - nums1[j]);
            ans -= v * v;
            if (c < k) {
                k -= c;
                continue;
            }

            v -= k / j;
            return ans + k % j * (v - 1) * (v - 1) + (j - k % j) * v * v;
        }

    }
};
int main()
{
    Solution slt;
    vector<int> nums1 = {7, 11, 4, 19, 11, 5, 6, 1, 8};
    vector<int> nums2 = {4, 7, 6, 16, 12, 9, 10, 2, 10};
    cout << slt.minSumSquareDiff(nums1, nums2, 3, 6);
    return 0;
}