// Expression of Graph
// 无向图 - Undirected graph
vector<unordered_set<int>> graph;

// Traverse
void dfs<node, parent>{
    for(int child:graph[node]){
        if(child != parent){
            dfs(child, node);
        }
    }
}