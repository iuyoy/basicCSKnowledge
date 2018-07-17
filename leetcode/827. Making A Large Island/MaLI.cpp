/*
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 1.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 1.
*/
// Union Find O(n^2) O(n^2)
class Solution {
private:
    unordered_map<int, int> ret;
    vector<int> pre;
    int re = 1;
    int unionsearch(int root) //查找根结点  
    {  
        int son, tmp;  
        son = root;  
        while(root != pre[root]) //寻找根结点  
            root = pre[root];  
        while(son != root) //路径压缩  
        {  
            tmp = pre[son];  
            pre[son] = root;  
            son = tmp;  
        }  
        return root;  
    }  

    void join(int root1, int root2) //判断是否连通，不连通就合并  
    {  
        int x, y;  
        x = unionsearch(root1);  
        y = unionsearch(root2);  
        if(x != y){ //如果不连通，就把它们所在的连通分支合并 
            pre[x] = y;  
        } 
    }  
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        pre = vector<int>(n*n+1);
        vector<vector<int>> dirs({{1,0}, {0,1}, {-1,0}, {0,-1}});
        // Build UnionFindSet
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]){
                    int a = i*n+j+1;
                    pre[a] = a;
                    for(auto dir:dirs){
                        int x = i+dir[0], y = j+dir[1];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]){
                            int b = x*n+y+1;
                            if(pre[b]==0)
                                pre[b] = b;
                            join(b, a);
                        }
                    }
                }
        // sum original area size
        for(int i=1;i<n*n+1;++i){
            int a = unionsearch(i);
            if(a!=0){
                ++ret[a];
                re = max(ret[a], re);  
            }
        }
        // change each zero and calcuate new area size
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                if(grid[i][j] == 0){
                    int r = 0;
                    set<int> roots;
                    for(auto dir:dirs){
                        int x = i+dir[0], y = j+dir[1];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]){
                            roots.insert(unionsearch(x*n+y+1));
                        }
                    }
                    for(int root:roots)
                        r+=ret[root];
                    re = max(re, r+1);
                }
            }
        return re;
    }
};
// Memroial BFS or DFS O(n^2) O(n^2)
// Straigth DFS O(n^4) O(n^2)
/*
[[1,0],[0,1]]
[[1, 1], [1, 0]]
[[1, 1], [1, 1]]
[[1,0,1],[1,0,1],[1,0,1]]
*/