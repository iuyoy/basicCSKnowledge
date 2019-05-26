/*
We are given a matrix with R rows and C columns has cells with integer coordinates (r, c), where 0 <= r < R and 0 <= c < C.

Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to largest distance.  Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that satisfies this condition.)

 

Example 1:

Input: R = 1, C = 2, r0 = 0, c0 = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (r0, c0) to other cells are: [0,1]
Example 2:

Input: R = 2, C = 2, r0 = 0, c0 = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
Example 3:

Input: R = 2, C = 3, r0 = 1, c0 = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
 

Note:

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C
*/

//Sort O(nlogn) n is R*C
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> rets;
        int idx = 0;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++){
                rets.push_back({abs(r0-i)+abs(c0-j), i,j});
            }
        sort(rets.begin(), rets.end(), greater<vector<int>>());
        vector<vector<int>> ret;
        while(rets.size()){
            ret.push_back({rets.back()[1], rets.back()[2]});
            rets.pop_back();
        }            
        return ret;
    }
};
//Good reading Sort O(nlogn) n is R*C
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ret;
        int idx = 0;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                ret.push_back({i, j});
            
        sort(ret.begin(), ret.end(), [r0, c0](vector<int>&a, vector<int>&b){
            return abs(a[0]-r0)+abs(a[1]-c0) < abs(b[0]-r0) + abs(b[1]-c0);
        });       
        return ret;
    }
};

// BFS generate by distance O(n) n is R*C 
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ret;
        queue<vector<int>> q;
        q.push({r0, c0});
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<vector<int>> visited(R, vector<int>(C, 0));
        visited[r0][c0] = 1;
        
        while(q.size()){
            int r = q.front()[0], c = q.front()[1];
            q.pop();
            ret.push_back({r,c});
            for(vector<int> dir:dirs){
                int rn = r+dir[0], cn = c+dir[1];
                if(0 <= rn && rn < R && 0 <= cn && cn < C && visited[rn][cn] == 0){
                    q.push({rn, cn});
                    visited[rn][cn] = 1;
                }
            }
        }
        return ret;
    }
};

// Counter Sort from https://leetcode.com/problems/matrix-cells-in-distance-order/discuss/278986/4ms-O(n)-Java-Counting-Sort-()-Solution

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<int> counter(R+C+1, 0);
        // count the number of specific distance
        // now counter[dis+1] means the length of such distance
        for(int i=0; i<R; ++i)
            for(int j=0; j<C; ++j){
                int dis = abs(i-r0)+abs(j-c0);
                counter[dis+1] ++;
            }
        // now counter[dis+1] means the end of such distance
        // counter[dis] means the start of such distance
        for(int i=1; i<=R+C; ++i)
            counter[i] += counter[i-1];
        
        vector<vector<int>> ret(R*C);
        for(int i=0; i<R; ++i)
            for(int j=0; j<C; ++j){
                int dis = abs(i-r0)+abs(j-c0);
                ret[counter[dis]++] = vector<int>({i,j});
            }
        
        return ret;
    }
};