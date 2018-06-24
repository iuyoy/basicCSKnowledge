/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
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
 // Post-Travel O(n) 
class Solution {
private:
    int getHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(abs(l-r)>1 || l==-1 || r== -1)
            return -1;
        else
            return 1+max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        return !(getHeight(root) == -1);
    }
};
