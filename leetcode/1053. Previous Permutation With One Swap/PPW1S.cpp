/*
Given an array A of positive integers (not necessarily distinct), return the lexicographically largest permutation that is smaller than A, that can be made with one swap (A swap exchanges the positions of two numbers A[i] and A[j]).  If it cannot be done, then return the same array.

 

Example 1:

Input: [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.
Example 2:

Input: [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.
Example 3:

Input: [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.
Example 4:

Input: [3,1,1,3]
Output: [1,3,1,3]
Explanation: Swapping 1 and 3.
 

Note:

1 <= A.length <= 10000
1 <= A[i] <= 10000
*/
// The origial problem description is wrong
// BST O(nlogn)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> idx;
        idx[A.back()] = n-1;
        set<int> bst;
        bst.insert(A.back());
        for(int i = n-2; i>=0; --i){
            auto f = bst.lower_bound(A[i]);
            if(f!=bst.begin()){
                f--;
                swap(A[i], A[idx[*f]]);
                break;
            }
            if(bst.find(A[i]) == bst.end()){
                bst.insert(A[i]);
                idx[A[i]] = i;
            }
        }
        return A;
    }
};

//Greedy O(n) Fixed Problem
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int left = n-2, right = -1;
        for(;left>=0 && A[left] <= A[left+1]; --left);
        if(left==-1) return A;
        for(int i=left+1; i<n; ++i)
            if(A[i] < A[left] && (right == -1 || A[i] > A[right]))
               right = i;
        swap(A[left], A[right]);
        return A;
    }
};