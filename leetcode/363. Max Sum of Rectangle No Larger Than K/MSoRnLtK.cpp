/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/
// Brute force O(n^4)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int m = matrix.size();
        if(m==0) return 0;
        const int n = matrix[0].size();
        int ret = INT_MIN;
        for(int i = 0; i<m; ++i){
            for(int j = 1; j<n; ++j){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int i = 1; i<m; ++i)
            for(int j = 0; j<n; ++j)
                matrix[i][j] += matrix[i-1][j];
        int area;
        if(ret!=k)
            for(int i = 0; i<m; ++i)
                for(int j = 0; j<n; ++j)
                    for(int i2 = i; i2<m;++i2)
                        for(int j2 = j; j2<n; ++j2){
                            if(i!=i2)
                                if(j2!=j)
                                    area = matrix[i2][j2]+matrix[i][j]-matrix[i2][j] - matrix[i][j2];
                                else
                                    area = matrix[i2][j2] - matrix[i][j2];
                            else
                                if(j2!=j)
                                    area = matrix[i2][j2] - matrix[i2][j];
                                else
                                    area = matrix[i2][j2];

                            if(k == area)
                                return k;
                            if(k>area)
                                ret = max(area, ret);

                        }
        return ret;
    }
};
