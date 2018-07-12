/*

We are given a binary tree (with root node root), a target node, and an integer value `K`.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]
Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.
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
// DFS? O(n) O(n)
class Solution {
private:
    // results
    vector<int> ret;
    // find the child-node which distace K from root.
    void find(TreeNode* root, int K){
        if(root == NULL) return;
        if(K == 0)
            ret.push_back(root->val);
        else{
            find(root->left, K-1);
            find(root->right, K-1);
        }
    }
    // find the target node, firstly.
    // find the parent-nodes by the return value,
    // find the sub-nodes by the other function.
    int find(TreeNode* root, TreeNode* target, int K){
        if(root == NULL) return -1;
        if(root->left == target){
            root->left = NULL;
            find(target, K);
            find(root, K-1);
            return K-2;
        }else if(root->right == target){
            root->right = NULL;
            find(root, K-1);
            find(target, K);
            return K-2;
        }
        int r = find(root->right, target, K);
        if(r>=0)
            if(r == 0){
                ret.push_back(root->val);
                return -1;
            }else{
                find(root->left, r-1);
                return r-1;
            }
        r = find(root->left, target, K);
        if(r>=0)
            if(r == 0){
                ret.push_back(root->val);
                return -1;
            }else{
                find(root->right, r-1);
                return r-1;
            }
        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == target)
            find(root, K);
        else
            find(root, target, K);
        return ret;
    }
};
/*
[3,5,1,6,2,0,8,null,null,7,4]
5
2
[3,5,1,6,2,0,8,null,null,7,4,null,null,null,null,9,10]
2
2
[3,5,1,6,2,0,8,null,null,7,4,null,null,null,null,9,10]
2
3
[0,5,1,null,null,2,6,null,3,null,null,4,null,7]
7
3
*/