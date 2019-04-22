/*
On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.

 

Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34
Example 3:

Input: [[1,0],[0,2]]
Output: 16
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
 

Note:

1 <= N <= 50
0 <= grid[i][j] <= 50
*/

// total surfaces - adjoin surfaces
// O(n^2)
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int num = 0;
        int adjoin = 0;
        int n = grid.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]){
                    num += grid[i][j];
                    adjoin += grid[i][j] - 1;
                    if(j != 0) adjoin += min(grid[i][j-1], grid[i][j]);
                    if(i != 0) adjoin += min(grid[i-1][j], grid[i][j]); 
                }
            }
        }
        return num*6 - adjoin*2;
    }
};