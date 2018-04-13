/*
You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
Output:
Merged tree:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7
Note: The merging process must start from the root nodes of both trees.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // If free the t2 after the fuction, t1 may lose some nodes.
 // If not, there will leave some memory garbage.
 // So, it is not a good solution.
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if(t1==NULL)//pay attention to two NULL conditions
        return t2;
    if(t2==NULL)
        return t1;
    t1->val += t2->val;
    if(t1->left!=NULL && t2->left!=NULL)
        mergeTrees(t1->left, t2->left);
    else if(t1->left==NULL)
        t1->left = t2->left;
    if(t1->right!=NULL && t2->right!=NULL)
        mergeTrees(t1->right, t2->right);
    else if(t1->right==NULL)
        t1->right = t2->right;
    return t1;
}

// A bette solution is to malloc a new space for the nodes that not in t1.
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if(!t1)//pay attention to two NULL conditions
        return t2;
    if(!t2)
        return t1;
    merge(t1, t2);
    return t1;
}
void merge(struct TreeNode* t1, struct TreeNode* t2) {
    t1->val += t2->val;
    if(t1->left && t2->left)
        merge(t1->left, t2->left);
    else if(!t1->left)
        t1->left = t2->left;
    if(t1->right && t2->right)
        merge(t1->right, t2->right);
    else if(!t1->right)
        t1->right = t2->right;
}
