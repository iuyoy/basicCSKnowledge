/*
We run a preorder depth first search on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  (If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0.)

If a node has only one child, that child is guaranteed to be the left child.

Given the output S of this traversal, recover the tree and return its root.

 

Example 1:



Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:



Input: "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
 

Example 3:



Input: "1-401--349---90--88"
Output: [1,401,null,349,88,90]
 

Note:

The number of nodes in the original tree is between 1 and 1000.
Each node will have a value between 1 and 10^9.
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

// O(n) n S.size()
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> layers(1000);
        int layer = 0, val = 0;
        TreeNode* root;
        for(int i=0; i<S.size(); ++i){
            if(S[i] == '-')
                ++layer;
            else{
                val = val*10 + S[i]-'0';
                if(i == S.size() - 1 || S[i+1] == '-'){
                    TreeNode* cur = new TreeNode(val);
                    if(layer != 0 ){
                        TreeNode* par = layers[layer-1];
                        if(par->left == nullptr)
                            par->left = cur;
                        else
                            par->right = cur;
                    }else
                        root = cur;
                    layers[layer] = cur;
                    layer = 0;
                    val = 0;
                }
            }
        }
        return root;
        
    }
};