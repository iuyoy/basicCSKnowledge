/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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
class Solution {
private:
    int ret;
public:
    int kthSmallest(TreeNode* root, int k) {
        int cur = 1;
        search(root, &cur, k);
        return ret;
    }
    bool search(TreeNode* root, int* cur, int k){
        if(root == NULL)
            return false;
        if(search(root->left, cur, k))
            return true;
        if(*cur == k){
            ret = root->val;
            return true;
        }
        else
            *cur += 1;
        return search(root->right, cur, k);
    }
};
