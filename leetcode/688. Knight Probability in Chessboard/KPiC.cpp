/*
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

Example:
Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.

*/

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<int> vi;
typedef vector<vi> vvi;


// memorialized DFS O(N*N*K)
class Solution {
private:
    double dfs(int r, int c, int& n, int k, vvvd& dp, vvi dir){
        if(r<0 || c<0 || r >= n || c>= n) return 0;
        if(k == 0) dp[r][c][0] = 1;
        if(dp[r][c][k] > 0.0)
            return dp[r][c][k];
        double ret = 0;
        for(int i=0; i<8; ++i){ 
            ret += dfs(r+dir[0][i], c+dir[1][i], n, k-1, dp, dir)/8.0;
        }
        dp[r][c][k] = ret;
        return ret;
    }
public:
    double knightProbability(int N, int K, int r, int c) {
        vvvd dp(N, vvd(N, vd(K+1, 0)));
        vvi dir({{-2,-1,-2,-1,2,1,2,1}, {-1,-2,1,2,-1,-2,1,2}});
        return dfs(r, c, N, K, dp, dir);
    }
};