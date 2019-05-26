/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

// DFS O(m*n)
class Solution {
public:
    vector<vector<int>> both;
    vector<vector<int>> visited;
    vector<vector<int>> dirs;
    int m;
    int n;
    void dfs(vector<vector<int>>& matrix, int i, int j, bool second){
        if( visited[i][j] - second == 1 ) return;
        if(second == false) 
            visited[i][j] = 1;
        else {
            if(visited[i][j] == 1)
                both.push_back({i, j});
            visited[i][j] = 2;
        }
        for (vector<int> dir : dirs) {
            int i2 = i + dir[0], j2 = j + dir[1];
            if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < n && matrix[i][j] <= matrix[i2][j2]) 
                dfs(matrix, i2, j2, second);
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0) return {};
        n = matrix[0].size();
        dirs = vector<vector<int>>({{-1, 0}, {0, -1}, {1, 0}, {0, 1}});
        visited = vector<vector<int>>(m, vector<int>(n));
        for(int i=0; i<m; ++i)
            dfs(matrix, i, 0, false);
        for(int j=0; j<n; ++j)
            dfs(matrix, 0, j, false);
        for(int i=0; i<m; ++i)
            dfs(matrix, i, n-1, true);
        for(int j=0; j<n; ++j)
            dfs(matrix, m-1, j, true);
        return both;
    }
};

//BFS
class Solution {
public:
    vector<vector<int>> both;
    vector<vector<int>> visited;
    vector<vector<int>> dirs;
    int m;
    int n;
    void bfs(vector<vector<int>> & matrix, queue<pair<int, int>>& q, int val){
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            if(visited[i][j] == 3) both.push_back({i,j});
            for (vector<int> dir : dirs) {
                int i2 = i + dir[0], j2 = j + dir[1];
                if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < n && matrix[i2][j2] >= matrix[i][j] && visited[i2][j2] < val ) {
                    visited[i2][j2] += val;
                    q.push({i2, j2});
                }
            }   
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0) return {};
        n = matrix[0].size();
        visited = vector<vector<int>>(m, vector<int>(n));
        queue<pair<int, int>> q;
        dirs = vector<vector<int>>({{-1, 0}, {0, -1}, {1, 0}, {0, 1}});
        
        for(int i=0; i<m; ++i){
            visited[i][0] = 1;
            q.push({i, 0});
        }
        for(int j=1; j<n; ++j){
            visited[0][j] = 1;
            q.push({0, j});
        }
        bfs(matrix, q, 1);
        for(int i=0; i<m; ++i){
            visited[i][n-1] |= 2;
            q.push({i, n-1});
        }
        for(int j=0; j<n-1; ++j){
            visited[m-1][j] |= 2;
            q.push({m-1, j});
        }
        bfs(matrix, q, 2);            
        return both;
    }
};

/*
[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
[[3,3,3,3,3,3],[3,0,3,3,0,3],[3,3,3,3,3,3]]
[[1,8,1]]
[[1,1,1],[1,8,1],[1,1,1]]
*/