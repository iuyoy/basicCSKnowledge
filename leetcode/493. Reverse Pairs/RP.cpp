/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/

// Merge Sort O(nlogn)
class Solution {
public:
    int mergeSort(vector<int>& nums, int l, int r){
        int ret = 0;
        if(l<r){
            int mid = (l+r)/2;
            ret += mergeSort(nums, l, mid);
            ret += mergeSort(nums, mid+1, r);
            vector<int> left(nums.begin()+l, nums.begin()+mid+1),
                right(nums.begin()+mid+1, nums.begin()+r+1);
            for(int i=0, j=0; i<left.size() && j<right.size();){
                if((long)left[i] > (long)2 * right[j]) {
                    ret += left.size() - i;
                    ++j;
                }else 
                    ++i;
            }
            for(int i=0, j=0; l<=r; ++l){
                if(i<left.size() && j<right.size()){
                    if(left[i] > right[j]){
                        nums[l] = right[j++];
                    }else
                        nums[l] = left[i++];
                }else if(i < left.size())
                    nums[l] = left[i++];
                else
                    nums[l] = right[j++];
            }
        }
        return ret;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
// BST O(n^2)
struct BST_Node {
    int val;
    int count;
    BST_Node *left;
    BST_Node *right;
    BST_Node(int x) : val(x), count(1), left(NULL), right(NULL) {}
};

 BST_Node* insert(BST_Node *root, int val) {
    if (root == nullptr)
        return new BST_Node(val);
    else if (val < root->val)
        root->left = insert(root->left, val);
    else {
        root->count++;
        if (val > root->val)
            root->right = insert(root->right, val);
    }
    return root;
}
int search(BST_Node *root, long val){
    if (root == nullptr) return 0;
    if (val < (long)root->val)
        return search(root->left, val) + root->count;
    if (val == (long)root->val)
        return root->count;
    return search(root->right, val);
}
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        BST_Node* root = nullptr;
        int ret = 0;
        for(auto num:nums){
            ret += search(root, (long)num*2+1);
            root = insert(root, num);
        }
        return ret;
    }
};
/*
[1,3,2,3,1]
[2,4,3,5,1]
[5,4,3,2,1,0]
[1]
[5,3,1,2,4]
*/