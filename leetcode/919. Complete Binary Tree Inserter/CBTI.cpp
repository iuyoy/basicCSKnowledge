/*
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.
 

Example 1:

Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]
Example 2:

Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]]
 

Note:

The initial given tree is complete and contains between 1 and 1000 nodes.
CBTInserter.insert is called at most 10000 times per test case.
Every value of a given or inserted node is between 0 and 5000.
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
// level order traversal
class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> next;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> cur({root});
        queue<TreeNode*> next;
        while(cur.size()){
            TreeNode* t = cur.front();
            cur.pop();
            
            if(t->left!=NULL)
                next.push(t->left);
            if(t->right!=NULL)
                next.push(t->right);
            else
                this->next.push(t);
            //push any node didn't have right sub-node.
            if(cur.empty())
                swap(cur, next);
        }
    }
    
    int insert(int v) {
        TreeNode* t = next.front();
        TreeNode* node = new TreeNode(v);
        if(t->left==NULL)
            t->left = node;
        else{// it's completed, remove from next queue.
            t->right = node;
            next.pop();
        }

        next.push(node);
        return t->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */

/*
["CBTInserter","insert","get_root"]
[[[1]],[2],[]]
["CBTInserter","insert","insert","get_root"]
[[[1,2,3,4,5,6]],[7],[8],[]]
*/