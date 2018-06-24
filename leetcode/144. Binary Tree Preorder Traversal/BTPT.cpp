/*

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
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
    void preorder(TreeNode* root){
        if(root == NULL) return;
        order.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return order;
    }
};
//iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        stack<TreeNode*> st;
        if(root != NULL) st.push(root);
        while(!st.empty()){
            TreeNode* tp = st.top();
            st.pop();
            order.push_back(tp->val);
            if(tp->right != NULL) st.push(tp->right);
            if(tp->left != NULL) st.push(tp->left);
        }
        return order;
    }
};
