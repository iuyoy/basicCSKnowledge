/*

An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given
as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only
if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and
stop at any node, you may revisit nodes multiple times, and you may reuse edges.



Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]


Note:

1 <= graph.length <= 12
0 <= graph[i].length < graph.length

*/

// DFS O(min(n!, n^3)) TLE
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
  private:
    int ret;
    int dfs(vi &visited, vvi &dp, int cur, int n, int dis) {
        // cout<<dis<<endl;
        int left = 12 * 12;
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                flag = 1;
                visited[i] = 1;
                left = min(left, dfs(visited, dp, i, n, dis + dp[cur][i]));
                visited[i] = 0;
            }
        }
        if (flag)
            return left;
        return dis;
    }

  public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size();
        ret = 12 * 12;
        vvi dp(n, vi(n, ret));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
            for (int j : graph[i]) {
                dp[i][j] = 1;
                // dp[j][i] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            vi visited(n, 0);
            visited[i] = 1;
            queue<int> next({i});
            while (next.size()) {
                int j = next.front();
                next.pop();
                for (int k : graph[j]) {
                    dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k]);
                    // dp[k][i] = dp[i][k];
                    if (visited[k] == 0) {
                        next.push(k);
                        visited[k] = 1;
                    }
                }
            }
        }
        vi visited(n, 0);
        for (int i = 0; i < n; ++i) {
            visited[i] = 1;
            ret = min(ret, dfs(visited, dp, i, n, 0));
            visited[i] = 0;
        }
        return ret;
    }
};

// memorialized DFS O(min(2^n*n, n^3)) AC
class Solution {
  private:
    int ret;
    int dfs(int used, vvi &dp, int cur, int n, vvi &dis) {
        if (dp[used][cur] == 0 && used != (1 << n) - 1) {
            int left = 13 * 13;
            for (int i = 0; i < n; ++i)
                if (((used >> i) & 1) == 0)
                    left = min(
                        left, 
                        dis[cur][i] +dfs((used | (1 << i)), dp, i, n, dis)
                    );
            dp[used][cur] = left;
        }
        return dp[used][cur];
    }

  public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size();
        ret = 12 * 12;
        vvi dis(n, vi(n, ret));
        // get shortest distance between any i to j by bfs
        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
            for (int j : graph[i])
                dis[i][j] = 1;
        }
        for (int i = 0; i < n; ++i) {
            vi visited(n, 0);
            visited[i] = 1;
            queue<int> next({i});
            while (next.size()) {
                int j = next.front();
                next.pop();
                for (int k : graph[j]) {
                    dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]);
                    if (visited[k] == 0) {
                        next.push(k);
                        visited[k] = 1;
                    }
                }
            }
        }

        
        vvi dp(1 << n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            ret = min(ret, dfs(1 << i, dp, i, n, dis));
        return ret;
    }
};

// DP O(n*2^n)
/*
[[1],[0,2],[1]]
[[1,2,3],[0],[0],[0]]
[[1],[0,2,4],[1,3,4],[2],[1,2]]
[[1], [0, 2], [1, 3], [2, 4], [3, 5], [4, 6], [5, 7], [6, 8], [7, 9], [8, 10],
[9, 11], [10]]
*/

/*
[[1],[0,2],[1]]
[[1,2,3],[0],[0],[0]]
[[1],[0,2,4],[1,3,4],[2],[1,2]]
[[1], [0, 2], [1, 3], [2, 4], [3, 5], [4, 6], [5, 7], [6, 8], [7, 9], [8, 10],
[9, 11], [10]]
*/