/*
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.
*/

//BFS split by set O(n) O(n)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        set<int> g1;
        set<int> g2;
        queue<int> idx;
        vector<bool> visited(graph.size());
        int g = 0;
        for(int i=0; i<graph.size(); ++i)
            if(visited[i] == false && graph[i].size()){
                idx.push(i);
                while(idx.size()){
                    int a = idx.front();
                    idx.pop();
                    visited[a] = true;
                    if(g1.find(a) != g1.end())
                        for(int j:graph[a]){
                            if(g1.find(j) != g1.end())
                                return false;
                            if(g2.find(j) == g2.end()){
                                g2.insert(j);
                                idx.push(j);
                            }
                        }
                    else{
                        g2.insert(a);
                        for(int j:graph[a]){
                            if(g2.find(j) != g2.end())
                                return false;
                            if(g1.find(j) == g1.end()){
                                g1.insert(j);
                                idx.push(j);
                            }
                        } 
                    }
                }
            }   
        return true;
    }
};

//BFS split by value O(n) O(n)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> mark(n);
        for(int i=0; i<n; ++i)
            if(mark[i] == 0) {
                mark[i] = 1;
                queue<int> bfs({i});
                while(bfs.size()){
                    int a = bfs.front();
                    bfs.pop();
                    for(int j:graph[a])
                        if(mark[j] == 0){
                            mark[j] = -mark[a];
                            bfs.push(j);
                        }else if(mark[j] == mark[a])
                            return false;
                }
            }
        return true;
    }
};
/*
[[1,3],[0,2],[1,3],[0,2]]
[[1],[0,3],[3],[1,2]]
[[1,2,3], [0,2], [0,1,3], [0,2]]
[[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]
*/