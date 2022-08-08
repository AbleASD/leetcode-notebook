/*
 * @Author: Able
 * @Date: 2022-07-22 21:48:24
 * @Last Modified by:   Able
 * @Last Modified time: 2022-07-22 21:48:24
 * @link https://leetcode.cn/problems/evaluate-boolean-binary-tree/ @endlink
 */
#include "bits/stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool postOrder(TreeNode *root)
    {
        if (root == 0)
        {
            return false;
        }
        else if (root->val == 1)
        {
            return true;
        }
        else if (root->val == 2)
        {
            return postOrder(root->left) || postOrder(root->right);
        }
        else
        {
            return postOrder(root->left) && postOrder(root->right);
        }
    }
    bool evaluateTree(TreeNode *root)
    {
        return postOrder(root);
    }
};

int main()
{
    string ret = "asd";
    char c = 'f';
    ret.push_back(c);
    cout << ret;
    return 0;
}