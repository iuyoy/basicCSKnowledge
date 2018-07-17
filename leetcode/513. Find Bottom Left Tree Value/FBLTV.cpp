/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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

// BFS O(n)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q({root, nullptr});
        int ret = root->val;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top != nullptr){
                if(top->left != nullptr)
                    q.push(top->left);
                if(top->right != nullptr)
                    q.push(top->right);
            }else{
                if(q.empty()) break;
                else{
                    ret = q.front()->val;
                    q.push(nullptr);
                }
            }
        }
        return ret;
    }
};
// Better BFS, pushing into queue from right node to left node.
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q({root});
        TreeNode* ret = root;
        while(!q.empty()){
            ret = q.front();
            q.pop();
            if(ret->right != nullptr)
                q.push(ret->right);
            if(ret->left != nullptr)
                q.push(ret->left);
        }
        return ret->val;
    }
};
/*
[2,1,3]
[1,2,3,4,null,5,6,null,7]
[1]
[1,2]
[1,null,2]
*/