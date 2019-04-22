/*
A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

Then, the game can end in 3 ways:

If ever the Cat occupies the same node as the Mouse, the Cat wins.
If ever the Mouse reaches the Hole, the Mouse wins.
If ever a position is repeated (ie. the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
Given a graph, and assuming both players play optimally, return 1 if the game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a draw.

 

Example 1:

Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0
Explanation:
4---3---1
|   |
2---5
 \ /
  0
 

Note:

3 <= graph.length <= 50
It is guaranteed that graph[1] is non-empty.
It is guaranteed that graph[2] contains a non-zero element. 
*/

// memorialized DFS
// Track all mouse's and cat's choices. memo[i][j] represents the result while mouse at node i and cat at node j.
// For each mouse's choice, res means the result of this choice:
// 1.if there is one cat's choice that cat can catch the mouse, res = 2
// 2.else if there is one cat's choice that leads to draw, res = 0;
// 3.all choices that mouse can reach node zero, res = 1;
//
// For all mouse's choice, 
// 1.if there exists one choice that res = 1, return 1;
// 2.else if there exists one choice that res = 0, return 0;
// 3.no choice can make mouse git rid of cat, return 2;

typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
private:
    int dfs(vvi& graph, vvi& memo, int mouse, int cat){
        if(memo[mouse][cat] == -1){
            memo[mouse][cat] = 0;// if the mouse and cat come back to these locations, it is a loop, i.e. a draw.
            int r = 2;
            //traverse all mouse's choices
            for(int next_m : graph[mouse]){
                if(next_m == cat) continue;// if the mouse's next step is cat's location, mouse is caught, pass this situation.
                int res = 1;
                //traverse all cat's choices
                for(int next_c : graph[cat]){
                    if(next_c == 0) continue;// pass the illegal case.
                    int ret = dfs(graph, memo, next_m, next_c);
                    if(ret == 2) { res = 2;break;}
                    if(ret == 0) res = 0;
                }
                if(res == 1) { r = 1; break; }
                if(res == 0) r = 0;
            }
            memo[mouse][cat] = r;
        }
        return memo[mouse][cat];
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vvi memo(n, vi(n, -1));
        for(int i=0;i<n;++i) {memo[i][i]=2; memo[0][i] = 1;}
        return dfs(graph, memo, 1, 2);
    }
};