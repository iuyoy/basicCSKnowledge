/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

// Greedy O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if(m == 0 || matrix[0].size()==0)
            return false;
        int i = 0, j = matrix[0].size() -1;
        while(i<m && j>=0){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};
// 2 Area Binary Search O(nlog(m))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        return search(matrix, target, 0, matrix.size(), 0, matrix[0].size());
    }
    bool search(vector<vector<int>>& matrix, int target, int tt, int bb, int ll, int rr){
        int mid_m = (tt+bb)/2, mid_n = (ll+rr)/2;
        int t=tt, b=bb;
        while(t<b){
            int mid = (t+b)/2;
            if(matrix[mid][mid_n] == target)
                return true;
            if(matrix[mid][mid_n] > target)
                b = mid;
            else
                t = mid+1;
        }
        if(t>tt && rr>mid_n+1 && search(matrix, target, tt, t, mid_n+1, rr)) return true;
        if(bb>t && mid_n>ll && search(matrix, target, t, bb, ll, mid_n)) return true;
        return false;
    }
};


// 4 Area Binary Search?
// T(n*n) = T(n*n/2) + T(n*n/4) + O(1) = T(n*n/4) + 2*T(n*n/8) + T(n*n/16)
// O(n) = 3^log(n*n, 4) = 3^log(n, 4)
// n*log(n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        return search(matrix, target, 0, matrix.size(), 0, matrix[0].size());
    }
    bool search(vector<vector<int>>& matrix, int target, int t, int b, int l, int r){
        if(l<r && t<b){
            int mid_m = (t+b)/2, mid_n = (l+r)/2;
            if(matrix[mid_m][mid_n] == target)
                return true;
            if(matrix[mid_m][mid_n] > target){
                if(search(matrix, target , t, b, l, mid_n)) return true;
                return search(matrix, target, t, mid_m, mid_n, r);
            }
            if(search(matrix, target, t, b, mid_n+1, r))
                return true;
            return search(matrix, target, mid_m+1, b, l, mid_n+1);
        }
        return false;
    }
};
