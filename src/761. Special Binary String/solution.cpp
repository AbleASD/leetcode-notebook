/*
 * @Author: Able
 * @Date: 2022-08-08 22:36:49
 * @Last Modified by: Able
 * @Last Modified time: 2022-08-08 23:23:04
 * @link https://leetcode.cn/problems/special-binary-string/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        // 参与交换的子串也为特殊子串
        // 第一个子串
        // TODO
        if (s.size() <= 2) return s;

        int cnt = 0, left = 0;
        vector<string> subs;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    subs.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                    left = i + 1;
                }
            }
        }

        sort(subs.begin(), subs.end(), greater<string>());
        return accumulate(subs.begin(), subs.end(), string(""));
    }
};

int main() {
    Solution slt;
    string s = "11011000";
    cout << slt.makeLargestSpecial(s) << endl;
    return 0;
}