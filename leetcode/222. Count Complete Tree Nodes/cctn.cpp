
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Binsearch O(n) n is the height.
class Solution {
private:
    int h;
    int binSearch(TreeNode* root, int cur){
        if(cur == this->h)
            return 1;
        if(cur == this->h-1){
            if(root->left == NULL)
                return 0;
            if(root->right == NULL)
                return 1;
        }
        TreeNode* p = root->left;
        int h = cur+1;
        while(p->right != NULL){
            p = p->right;
            ++h;
        }
        if(h == this->h){
            if(root->right == NULL)
                return 1;
            return (1<<h-cur-1) + binSearch(root->right, cur+1);
        }
        else if(h < this->h){
            if(p->left != NULL)
                return (1<<h-cur)-1;
            else
                return binSearch(root->left, cur+1);
        }
    }

public:
    int countNodes(TreeNode* root) {
        h = 1;
        TreeNode* p = root;
        if(root == NULL)
            return 0;
        while(p->left!=NULL){
            ++h;
            p = p->left;
        }
        int more = binSearch(root, 1);
        return (1<<h-1) - 1 + more;
    }
};
