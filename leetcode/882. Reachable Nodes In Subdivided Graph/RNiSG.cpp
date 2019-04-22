/*
Starting with an undirected graph (the "original graph") with nodes from 0 to N-1, subdivisions are made to some of the edges.

The graph is given as follows: edges[k] is a list of integer pairs (i, j, n) such that (i, j) is an edge of the original graph,

and n is the total number of new nodes on that edge. 

Then, the edge (i, j) is deleted from the original graph, n new nodes (x_1, x_2, ..., x_n) are added to the original graph,

and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n), (x_n, j) are added to the original graph.

Now, you start at node 0 from the original graph, and in each move, you travel along one edge. 

Return how many nodes you can reach in at most M moves.

 

Example 1:

Input: edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
Output: 13
Explanation: 
The nodes that are reachable in the final graph after M = 6 moves are indicated below.

Example 2:

Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
Output: 23
 

Note:

0 <= edges.length <= 10000
0 <= edges[i][0] < edges[i][1] < N
There does not exist any i != j for which edges[i][0] == edges[j][0] and edges[i][1] == edges[j][1].
The original graph has no parallel edges.
0 <= edges[i][2] <= 10000
0 <= M <= 10^9
1 <= N <= 3000
A reachable node is a node that can be travelled to using at most M moves starting from node 0.

*/

// Dijkstra likely, use moves as comparison, not distance.
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        unordered_map<int, unordered_map<int, int>> graph;
        for(vector<int> edge:edges){
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        vector<int> moves(N, -1);
        vector<int> visited(N, 0);
        moves[0] = M;
        priority_queue<pair<int, int>> pq;
        pq.push({M, 0});
        int ret = 0;
        while(pq.size()){
            int i = pq.top().second;
            pq.pop();
            if(!visited[i]){
                for(auto b:graph[i]){
                    int j = b.first, dis = b.second;
                    if(visited[j]){
                        if(moves[j] <= dis)
                            ret += min(dis-moves[j], moves[i]);
                    }else{
                        ret += min(moves[i], dis);
                        if(moves[i] - dis - 1 > moves[j]){
                            moves[j] = moves[i] - dis - 1;
                            pq.push({moves[j], j});
                        } 
                    }
                }
                ++ret;
                visited[i] = 1;
            }
        }
        return ret;
    }
};
/*
[[0,1,10],[0,2,1],[1,2,2]]
6
3
[[0,1,10],[0,2,1],[1,2,2]]
8
3
[[0,1,10],[0,2,1],[1,2,2]]
11
3
[[0,1,4],[1,2,6],[0,2,8],[1,3,1]]
10
4
[[0,3,8],[0,1,4],[2,4,3],[1,2,0],[1,3,9],[0,4,7],[3,4,9],[1,4,4],[0,2,7],[2,3,1]]
8
5
*/