/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

 

Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Explanation:

 

Note:

1 <= N <= 20
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
// divide and conquer
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ret;
        if(N%2 == 0) return ret;
        if(N == 1) {
            TreeNode* root = new TreeNode(0); 
            ret.push_back(root);
            return ret;
        }
        for(int i=1; i<N; i+=2){
            vector<TreeNode*> left= allPossibleFBT(i);
            vector<TreeNode*> right= allPossibleFBT(N-1-i);
            for(TreeNode* l:left)
                for(TreeNode* r:right){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ret.push_back(root);
                }
        }
    return ret;

    }
};