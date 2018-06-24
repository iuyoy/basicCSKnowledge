/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
// recursive O(n)
class Solution {
private:
    int ret = INT_MIN;
    int recursion(TreeNode* root){
        if(root==NULL) return INT_MIN;
        int left = recursion(root->left);
        int right = recursion(root->right);
        if(left<0) left = 0;
        if(right<0) right =0;
        int cur = max(root->val + left, root->val + right);
        ret = max(cur, ret);
        ret = max(ret, root->val+left+right);
        return cur;
    }
public:
    int maxPathSum(TreeNode* root) {
        recursion(root);
        return ret;
    }
};
/*
[1,2,3]
[-10,9,20,null,null,15,7]
[-10,-1,-2]
[-1,-2]
[5,4,8,11,null,13,4,7,2,null,null,null,1]
*/
