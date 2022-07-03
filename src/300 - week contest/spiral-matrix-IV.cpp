/*
 * @Author: Able 
 * @Date: 2022-07-03 15:11:50 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-03 15:43:16
 * @link https://leetcode.cn/problems/spiral-matrix-iv/ @endlink
 */


#include <bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // m row and n col
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int x = 0, y = 0;
        int direct = 0;

        auto check = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == -1;
        };
        while (head) {
            matrix[x][y] = head->val;
            head = head->next;
            int cnt = 0;
            while (not check(x + dx[direct], y + dy[direct]) && cnt < 4) {
                direct = (direct + 1) / 4;
                cnt++;
            }
            if (cnt >= 4) break;
            x += dx[direct];
            y+= dy[direct];
        }
        return matrix;
    }
};