/*
An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.

The ith edge connects nodes edges[i][0] and edges[i][1] together.

Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.

Example 1:

Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: 
Here is a diagram of the given tree:
  0
 / \
1   2
   /|\
  3 4 5
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
Note: 1 <= N <= 10000
*/

// DFS O(n) O(n)
class Solution {
private:
    vector<int> cot;// number of child-nodes
    vector<int> ret;// distance of all child-nodes
    vector<unordered_set<int>> graph;
    
    int dfs(int root, int parent){
        for(int child:graph[root])
            if(child!=parent){
                cot[root] += dfs(child, root);
                ret[root] += cot[child]+ret[child];
            }
        return cot[root];
    }
    void help(int root, int parent, int N){
        for(auto child:graph[root]){
            if(child!=parent){
                ret[child] = ret[root] - cot[child] + N - cot[child];
                help(child, root, N);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        cot = vector<int>(N, 1);
        ret = vector<int>(N);
        graph = vector<unordered_set<int>>(N);
        if(N==1) return ret;
        for(auto edge:edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        dfs(0, 0);
        help(0, 0, N);
        return ret;
    }
};
/*
1
[]
6
[[0,1],[0,2],[2,3],[2,4],[2,5]]
2
[[1,0]]
3
[[2,0],[1,0]]
3
[[0,2],[0,1]]
4
[[1,2],[2,0],[0,3]]
4
[[2,1],[0,2],[0,3]]
*/