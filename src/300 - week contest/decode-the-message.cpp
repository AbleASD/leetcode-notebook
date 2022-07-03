/*
 * @Author: Able 
 * @Date: 2022-07-03 13:50:33 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-03 13:57:04
 * @link https://leetcode.cn/problems/decode-the-message/ @endlink
 */

// You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

// Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
// Align the substitution table with the regular English alphabet.
// Each letter in message is then substituted using the table.
// Spaces ' ' are transformed to themselves.
// For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
// Return the decoded message.

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> vis(26), mp(26);
        int cnt = 0;

        for (auto &k : key) {
            if (k != ' ') {
                if (!vis[k - 'a']) {
                    vis[k - 'a'] = 1;
                    mp[k - 'a'] = 'a' + cnt++;
                }
            }
        }
        for (auto &m : message) {
            if (m != ' ') {
                m = mp[m - 'a'];
            }
        }
        return message;
    }
};

int main() {
    Solution slt;
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    cout << slt.decodeMessage(key, message);
    return 0;
}