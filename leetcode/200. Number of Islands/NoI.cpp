/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/
// DFS O(m*n)
class Solution {
private:
    int m;
    int n;
    void painter(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        vector<vector<int>> dirs({{-1,0},{0,-1},{1,0},{0,1}});
        for(auto dir:dirs){
            int i2 = i+dir[0], j2 = j+dir[1];
            if(i2>=0 && i2<m && j2>=0 && j2<n && grid[i2][j2] == '1'){
                painter(grid, i2, j2);
            }
        } 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        m = grid.size();
        if(m == 0) return ret;
        n = grid[0].size();
        for(int i=0; i<m; ++i)
            for(int j = 0; j<n; ++j)
                if(grid[i][j] == '1'){
                    ++ret;
                    painter(grid, i, j);
                }
        return ret;
    }
};