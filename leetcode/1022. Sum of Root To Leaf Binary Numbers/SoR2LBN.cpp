/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
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

// dfs cal from bottom to top O(n^2)
class Solution {
public:
    int ret;
    void cal(TreeNode* root, int val, vector<int>& deeps){
        if(root != nullptr){
            vector<int> l = dfs(root);
            for(int deep:l){
                ret += (val << deep);
                deeps.push_back(deep+1);
            }
        }
    }
    vector<int> dfs(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr){
            ret += root->val;
            return {1};
        }
        vector<int> deeps;
        cal(root->left, root->val, deeps);
        cal(root->right, root->val, deeps);
        return deeps;
    }
    int sumRootToLeaf(TreeNode* root) {
        ret = 0;
        dfs(root);
        return ret;
    }
};

// dfs from top to bottom O(n)
class Solution {
public:
    int ret;
    void dfs(TreeNode* root, int csum){
        csum = root->val + (csum<<1);
        if(root->left == nullptr && root->right == nullptr){
            ret += csum;
            return;
        }
        
        if(root->left != nullptr)
            dfs(root->left, csum);
        if(root->right != nullptr)
            dfs(root->right, csum);
    }
    int sumRootToLeaf(TreeNode* root) {
        ret = 0;
        dfs(root, 0);
        return ret;
    }
};