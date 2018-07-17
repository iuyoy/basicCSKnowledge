/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.


Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].
*/
// O(m*n)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int target;
        if(m == 0 || n == 0) return true;
        int si = m-1, sj = 0;
        while(sj<n){
            target = matrix[si][sj];
            int i = si+1, j = sj+1;
            while(i<=m&&j<=n){
                if(matrix[i++][j++]!=target)
                    return false;
            }
            if(si != 0)
                --si;
            else
                ++sj;
        }
        return true;
    }
};
