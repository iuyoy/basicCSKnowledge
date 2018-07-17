/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
*/
// Brute Force O(m*n)
class Solution {
private:
    bool isMagicSqure(vector<vector<int>> grid, int i, int j){
        vector<bool> nums(9);
        vector<int> sums(8);
        for(int x=0; x<3; x++){
            int sum = 0;
            for(int y=0; y<3; ++y){
                int num = grid[i+x][j+y];
                if(num>9 || num <1 || nums[num])
                    return false;
                nums[num] = true;
                sums[x]+=num;
                sums[3+y]+=num;
                if(x==y) sums[6]+=num;
                if(x+y==2) sums[7]+=num;
            }
        }
        for(int sum:sums)
            if(sum!=15)
                return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size()-2;
        if(m<1) return 0;
        int n = grid[0].size()-2;
        int ret = 0;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                ret += isMagicSqure(grid, i, j);
        return ret;
    }
};