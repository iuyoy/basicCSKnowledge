/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:

Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3 
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
*/

struct BSTNode {
    int val;
    int count;
    int count_left;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x) : val(x), count(1), count_left(0), left(NULL), right(NULL) {}
};

BSTNode* insert(BSTNode *root, int val) {
    if (root == nullptr)
        return new BSTNode(val);
    else if (val < root->val){
        root->count_left ++;
        root->left = insert(root->left, val);
    }else if (val == root->val)
        root->count++;
    else
        root->right = insert(root->right, val);
    return root;
}
int search(BSTNode *root, long val) {
    if (root == nullptr)
        return 0;
    else if (val < root->val)
        return search(root->left, val);
    else if (val == root->val)
        return root->count + root->count_left;
    else
        return root->count + root->count_left + search(root->right, val);
}
// BST O(nlogn)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        BSTNode* root = new BSTNode(0);
        long sum = 0, ret = 0;
        for(int num:nums){
            sum += num;
            ret += search(root, sum-lower) - search(root, sum-upper-1);
            insert(root, sum);
        }
        return ret;
    }
};
/*
[-2,5,-1]
-2
2
[1,-1,2,-2,3,-4,-4,-2,2,3,4,3,2,5,6,6,7,-1,-2]
-5
5
[1,-1,2,-2,3,-4,-4,-2,2,3,4,3,2,5,6,6,7,-1,-2]
0
0
[1,-1,2,-2,3,-4,-4,-2,2,3,4,3,2,5,6,6,7,-1,-2]
-2
0
[1,-1,2,-2,3,-4,-4,-2,2,3,4,3,2,5,6,6,7,-1,-2]
0
2
[2147483647,-2147483648,-1,0]
-1
0
[-2147483647,0,-2147483647,2147483647]
-564
3864
*/