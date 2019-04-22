/*
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
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
// recursion, definition of tree traversals
class Solution {
public:
    TreeNode* recursion(vector<int>& pre, int l1, int r1, vector<int>& post, int l2, int r2){
        if(l1>r1 || l2>r2) return nullptr;
        TreeNode* root = new TreeNode(pre[l1]);
        if(l1 != r1){
            ++l1; --r2;
            if(pre[l1] == post[r2])
                root->left = recursion(pre, l1, r1, post, l2, r2);
            else{
                for(; r1>=l1 && pre[r1] != post[r2]; --r1);
                for(; l2<=r2 && post[l2] != pre[l1]; ++l2);
                root->left = recursion(pre, l1, r1-1, post, 0, l2);
                root->right = recursion(pre, r1, post.size()-1, post, l2+1, r2);
            }
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return recursion(pre, 0, pre.size()-1, post, 0, pre.size()-1);
    }
};