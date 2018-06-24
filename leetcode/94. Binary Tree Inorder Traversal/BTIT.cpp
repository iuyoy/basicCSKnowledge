/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
//Recursion
class Solution {
private:
    vector<int> order;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        order.push_back(root->val);
        inorder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return order;
    }
};
// Iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != NULL || !st.empty()){
            while(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            order.push_back(cur->val);
            cur = cur->right;
        }
        return order;
    }
};
