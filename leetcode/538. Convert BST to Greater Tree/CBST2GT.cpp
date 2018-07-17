/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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

// Recursion O(n) O(n)
class Solution {
private:
    int convert(TreeNode* root, int sum){
        if(root!=NULL){
            root->val += convert(root->right, sum);
            // if(root->right != NULL){
            //     root->val += convert(root->right, sum);
            // }else{
            //     root->val += sum;
            // }
            return convert(root->left, root->val);
            // if(root->left != NULL){
            //     return convert(root->left, root->val);
            // }
            // return root->val;
        }
        return sum;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        convert(root, 0);
        return root;
    }
};

// Recursion O(n) O(n) simailar as the above method
class Solution {
private:
    int sum = 0;
    void convert(TreeNode* root){
        if(root!=NULL){
            convert(root->right);
            root->val += sum;
            sum = root->val;
            convert(root->left);
        }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }
};
