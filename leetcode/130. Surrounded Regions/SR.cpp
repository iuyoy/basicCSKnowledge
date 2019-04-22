/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/
typedef vector<vector<char>> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;


// BFS 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        vvi visited(m, vi(n, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(board[i][j] == 'X')
                    visited[i][j] = 1;
                else if(i ==0 || i == m-1 || j==0 || j== n -1){
                    q.push({i, j});
                    visited[i][j] = -1;
                }
        vvi dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(q.size()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(auto dir:dirs){
                int i = x + dir[0], j = y + dir[1];
                if(0<i && i<m && 0<j && j<n && visited[i][j] == 0){
                    visited[i][j] = -1;
                    q.push({i, j});
                }
            }
        }
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(visited[i][j] == 0)
                    board[i][j] = 'X';
        
    }
};