/*
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000
*/

#define N 10001
// Union Find with Compression
vector<int> par(N, -1);
int Find(int x) {
    int r = x;
    while (r != par[r])
        r = par[r];
    int i = x, j;
    while (par[i] != r) {
        j = par[i];
        par[i] = r;
        i = j;
    }
    return r;
}

void mix(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx != fy) {
        par[fy] = fx;
    }
}

// Union find O(n) and greedy
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> x(N, -1), y(N, -1);
        for(int i=0; i<stones.size(); ++i){
            par[i] = i;
            if(x[stones[i][0]] == -1){
                x[stones[i][0]] = i;
                if(y[stones[i][1]] == -1)
                    y[stones[i][1]] = i;
                else
                    mix(y[stones[i][1]], i);
            }else{
                mix(x[stones[i][0]], i);
                if(y[stones[i][1]] == -1)
                    y[stones[i][1]] = i;
                else
                    mix(x[stones[i][0]], y[stones[i][1]]);
            }
        }
        int ret = 0;
        for(int i=0; i<stones.size(); ++i)
            if(par[i] == i)
                ++ret;
        return stones.size() - ret;
    }
};
/*
[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
[[0,0],[0,2],[1,1],[2,0],[2,2]]
[[0,0]]
[[5,9],[9,0],[0,0],[7,0],[4,3],[8,5],[5,8],[1,1],[0,6],[7,5],[1,6],[1,9],[9,4],[2,8],[1,3],[4,2],[2,5],[4,1],[0,2],[6,5]]
*/