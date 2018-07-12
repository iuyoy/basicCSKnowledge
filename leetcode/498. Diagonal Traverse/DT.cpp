/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/
//Math O(m*n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if(m == 0) return ret;
        int n = matrix[0].size();
        --m; --n;
        int dia = m+n;
        for(int d=0, flag=0; d<=dia; ++d){
            if(flag)// Judge from left to right or from right to left
                for(int i=max(0, d-n); i<=min(d, m); ++i)//Calculate start and end.
                    ret.push_back(matrix[i][d-i]);
            else
                for(int j=max(0, d-m); j<=min(d, n); ++j)
                    ret.push_back(matrix[d-j][j]);
            flag = !flag;
        }
        return ret;
    }
};
/*
[[1,2,3],[4,5,6],[7,8,9]]
[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
[[]]
[]
[[1]]
[[1,2]]
[[1],[2]]
*/