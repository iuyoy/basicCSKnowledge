/*
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

Example 1:



Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 

Note:

The number of nodes in the tree is between 2 and 5000.
Each node will have value between 0 and 100000.
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

// bottom to up O(n) n is the node number
class Solution {
public:
    int ret;
    int maxAncestorDiff(TreeNode* root) {
        ret = 0;
        dfs(root);
        return ret;
    }
    vector<int> dfs(TreeNode* root){
        // if(root == nullptr) return {-1, -1};
        int min_value = root->val, max_value = root->val;
        if(root->left){
            auto left = dfs(root->left);
            ret = max( max(abs(root->val - left[0]),abs(root->val - left[1])), ret);
            min_value = min(left[0], min_value);
            max_value = max(left[1], max_value);
        }
        if(root->right){
            auto right = dfs(root->right);
            ret = max( max(abs(root->val - right[0]),abs(root->val - right[1])), ret);
            min_value = min(right[0], min_value);
            max_value = max(right[1], max_value);
        }
        return {min_value, max_value};
    }
};

// top to bottom O(n) n is the node number
class Solution {
public:
    int ret;
    int maxAncestorDiff(TreeNode* root) {
        ret = 0;
        dfs(root->left, root->val, root->val);
        dfs(root->right, root->val, root->val);
        return ret;
    }
    void dfs(TreeNode* root, int min_value, int max_value){
        if(root == nullptr) return;
        ret = max( max(abs(root->val - min_value), abs(root->val - max_value)), ret);
        min_value = min(root->val, min_value);
        max_value = max(root->val, max_value);
        dfs(root->left, min_value, max_value);
        dfs(root->right, min_value, max_value);
    }
};