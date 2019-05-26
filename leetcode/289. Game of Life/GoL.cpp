/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/
// O(mn)
class Solution {
public:
    vector<vector<int>> dirs;
    void gameOfLife(vector<vector<int>>& board) {
        dirs = vector<vector<int>>({{-1,1},{0,1},{1,1},{-1,0},{1,0},{-1,-1},{0,-1},{1,-1}});
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j){
                int cot = 0;
                for (vector<int> dir : dirs) {
                    int i2 = i + dir[0], j2 = j + dir[1];
                    if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < n && board[i2][j2] > 0) 
                        cot++;
                }
                if(board[i][j] == 1 && (cot == 2 || cot ==3))
                    board[i][j] = 2;
                if(board[i][j] == 0 && cot == 3)
                    board[i][j] = -1;
            }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if(board[i][j] == -1 || board[i][j] == 2)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
    }
};