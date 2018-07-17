/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/
// HeapSort + DP O(mnlog(mn)) O(mn)
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if(m==0) return 0;
        const int n = matrix[0].size();
        if(n == 0) return 0;
        vector<vector<int>> dir({{-1,0,1,0},{0,-1,0,1}});
        vector<vector<int>> path(m, vector<int>(n, 1));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i<m; ++i)
            for(int j =0; j<n; ++j)
                pq.push({matrix[i][j], i, j});
        int ret = 1;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            for(int i = 0; i<4; ++i){
                int x = top[1]+dir[0][i], y = top[2]+dir[1][i];
                if(x>=0 && x<m && y>=0 && y<n)
                    if(matrix[x][y] > top[0] && path[x][y] <= path[top[1]][top[2]]){
                        path[x][y] = path[top[1]][top[2]] + 1;
                        ret = max(ret, path[x][y]);
                    }
            }
        }
        // for(auto a:path){
        //     for(auto b:a)
        //         cout<<b<<" ";
        //     cout<<endl;
        // }

        return ret;
    }
};

//DP + DFS O(mn) Find the val of start
class Solution {
private:
    int m;
    int n;
    vector<vector<int>> dp;
    vector<vector<int>> dirs;

    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]) return dp[i][j];
        int ret = 1;
        for(auto dir:dirs){
            int i2 = i+dir[0], j2 = j+dir[1];
            if(i2>=0 && i2<m && j2>=0 && j2<n && matrix[i2][j2] > matrix[i][j])
                ret = max(ret, dfs(matrix, i2, j2)+1);
        }
        dp[i][j] = ret;
        return ret;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m==0) return 0;
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        dirs = vector<vector<int>>({{-1,0},{0,-1},{1,0},{0,1}});
        int ret = 0;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                ret = max(ret, dfs(matrix, i, j));
        return ret;
    }
};
