/*Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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

// dfs O(n)
class Solution {
public:
    int mlen;
    int dfs(TreeNode* root, int par){
        if(root == nullptr) return 0;
        int l = dfs(root->left, root->val),
            r = dfs(root->right, root->val);
        mlen = max(mlen, l+r);
        if(root->val == par)
            return max(l,r)+1;
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        mlen = 0;
        dfs(root, root->val-1);
        return mlen;
    }
};