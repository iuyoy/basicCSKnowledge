/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
// DP O(m*n) O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<int> dp(n, 1);
        int i = 0;
        for(;i<n&&obstacleGrid[0][i]==0;++i);
        for(;i<n;++i)
            dp[i] = 0;
        for(int i = 1;i<m;++i)
            for(int j = 0;j<n;++j)
                if(obstacleGrid[i][j])
                    dp[j] = 0;
                else if(j>0)
                    dp[j] += dp[j-1];
        return dp[n-1];
    }
};
