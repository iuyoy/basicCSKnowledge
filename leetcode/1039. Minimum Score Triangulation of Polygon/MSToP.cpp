/*
Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.

Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the product of the labels of the vertices, and the total score of the triangulation is the sum of these values over all N-2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

 

Example 1:

Input: [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
Example 2:



Input: [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.
Example 3:

Input: [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
 

Note:

3 <= A.length <= 50
1 <= A[i] <= 100
*/
// Burst balloon like, O(n^3)
class Solution {
public:

    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        int dp[n+1][n+1];
        A.push_back(A[0]);

        memset(dp, 0, sizeof(dp));
        
        for(int len = 0; len<n-1; ++len)
            for(int l = 1; l+len<n; ++l){
                int r = l + len;
                dp[l][r] = INT_MAX;
                for(int m=l; m<=r; ++m)
                    dp[l][r] = min(dp[l][r], A[l-1]*A[m]*A[r+1] + dp[l][m-1] + dp[m+1][r]);
            }
        return min(dp[1][n-2], dp[2][n-1]);
    }
};


// update O(n^3)
class Solution {
public:

    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int len = 2; len<n; ++len)
            for(int l = 0; l+len<n; ++l){
                int r = l + len;
                dp[l][r] = INT_MAX;
                for(int m=l+1; m<r; ++m)
                    dp[l][r] = min(dp[l][r], A[l]*A[m]*A[r] + dp[l][m] + dp[m][r]);
            }
        return dp[0][n-1];
    }
};