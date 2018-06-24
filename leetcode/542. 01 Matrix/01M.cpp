/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1:
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2:
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/
// BFS O(n) n is the total nodes of matrix
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> dirs({{1,0},{0,1},{-1,0},{0,-1}});
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                if(matrix[i][j] == 0)
                    que.push({i,j});
                else
                    matrix[i][j] = INT_MAX;
            }
        while(!que.empty()){
            int i = que.front().first, j = que.front().second;
            que.pop();
            for(auto dir:dirs){
                int x = i+dir[0], y = j+dir[1];
                if(x>=0 && x<m && y>=0 && y<n && matrix[i][j] + 1 < matrix[x][y]){
                    matrix[x][y] = matrix[i][j]+1;
                    que.push({x,y});
                }
            }
        }
        return matrix;
    }
};
// DP O(n)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 20000));
        int i, j;
        // From up left to down right
        for(i=0;i<m;++i)
            for(j=0;j<n;++j){
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else{
                    if(i>0) dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                    if(j>0) dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
                }
            }
        // from down right to up left
        for(i=m-1;i>=0;--i)
            for(j=n-1;j>=0;--j){
                if(i<m-1) dp[i][j] = min(dp[i+1][j]+1, dp[i][j]);
                if(j<n-1) dp[i][j] = min(dp[i][j+1]+1, dp[i][j]);
            }
        return dp;
    }
};
/*
[[0,0,0],[0,1,0],[0,0,0]]
[[0,0,0],[0,1,0],[1,1,1]]
[[1,1,1],[1,0,1],[1,1,1]]
[[0,1,1],[1,1,1],[1,1,0]]
*/
