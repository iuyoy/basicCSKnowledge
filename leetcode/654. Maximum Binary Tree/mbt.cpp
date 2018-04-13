/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    /
     2  0
       \
        1
Note:
The size of the given array will be in the range [1,1000].
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
 // Divide and conquer TC:O(n^2) SC:O(n)
 // O(n) algorithm exist on https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C++-O(N)-solution
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dc(nums, 0, nums.size()-1);
    }
    TreeNode* dc(vector<int>nums, int l, int r){
        if(l>r)
            return nullptr;
        int mid = max(nums, l, r);
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dc(nums, l, mid-1);
        node->right = dc(nums, mid+1, r);
        return node;
    }
    int max(vector<int>nums, int l, int r){
        int max_i = l;
        for(int i = l + 1;i<=r;++i){
            if(nums[i]>nums[max_i])
                max_i = i;
        }
        return max_i;
    }
};
