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
 // Divide and conquer TC: Avg O(nlogn) SC:O(n)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int l, int r){
        if(l>r) return nullptr;
        int max_i = l;
        for(int i=l+1; i<=r; ++i)
            if(nums[max_i] < nums[i])
                max_i = i;
        TreeNode* node = new TreeNode(nums[max_i]);
        node->left = constructMaximumBinaryTree(nums, l, max_i-1);
        node->right = constructMaximumBinaryTree(nums, max_i+1, r);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return constructMaximumBinaryTree(nums, 0, n-1);
    }
};


// My stack solution O(n)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        stack<TreeNode*> st;
        for(int num:nums){
            TreeNode* node = new TreeNode(num);
            TreeNode* temp_left = nullptr;
            while(st.size() && st.top()->val < num){
                st.top()->right = temp_left;
                temp_left = st.top();
                st.pop();
            }
            node->left = temp_left;
            st.push(node);
        }
        TreeNode* temp_left = nullptr;
        while(st.size()){
            st.top()->right = temp_left;
            temp_left = st.top();
            st.pop();
        }
        return temp_left;
    }
};

//Stack with less code O(n) algorithm from https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C++-O(N)-solution
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        stack<TreeNode*> st;
        TreeNode* root = nullptr;
        for(int num:nums){
            TreeNode* node = new TreeNode(num);
            while(st.size() && st.top()->val < num){
                node->left = st.top();
                st.pop();
            }
            if(st.size()) 
                st.top()->right = node;
            else
                root = node;
            st.push(node);
        }
        return root;
    }
};