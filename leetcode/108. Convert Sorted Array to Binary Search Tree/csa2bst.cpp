/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = dc(nums, 0, nums.size()-1);
        return root;
    }
    TreeNode* dc(vector<int> nums, int l, int r){
        TreeNode* root;
        if(l>r)
            root = nullptr;
        else{
            int mid = l+(r-l+1)/2;
            root = new TreeNode(nums[mid]);
            root->left = dc(nums, l, mid-1);
            root->right = dc(nums, mid+1, r);
        }
        return root;
    }
};
