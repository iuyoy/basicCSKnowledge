/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// cursion O(n)
class Solution {
private:
    vector<vector<int>> rets;
    void recursion(TreeNode* root, int sum, vector<int>& ret){
        if(root == NULL) return;
        ret.push_back(root->val);
        sum -= root->val;
        if(root->left == NULL && root->right == NULL && 0 == sum)
            rets.push_back(ret);
        recursion(root->left, sum, ret);
        recursion(root->right, sum, ret);
        ret.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> ret;
        recursion(root, sum, ret);
        return rets;
    }
};
