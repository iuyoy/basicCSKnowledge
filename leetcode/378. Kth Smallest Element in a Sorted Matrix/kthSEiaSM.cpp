/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
// https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378
// Binary Search O(log(max-min)*n*log(n))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while(1){
            int sm = 0, lg = 0;
            int mid = l + (r-l)/2;
            for(int i = 0; i<n; ++i){
                sm += distance(matrix[i].begin(), lower_bound(matrix[i].begin(), matrix[i].end(), mid));
                lg += distance(matrix[i].begin(), upper_bound(matrix[i].begin(), matrix[i].end(), mid));
                // sm += lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                // lg += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            // cout <<mid<<" "<<sm<<" "<<lg<<endl;
            if(k<=sm)
                r = mid-1;
            else if(k>lg)
                l = mid+1;
            else
                return mid;
        }
        return 0;
    }
};
