/*
You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

 

Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
 

Note:

1 <= N <= 10000
0 <= paths.size <= 20000
No garden has 4 or more paths coming into or leaving it.
It is guaranteed an answer exists.
*/

// BFS
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> rets(N, 0);
        vector<set<int>> path(N+1);
        for(vector<int> p:paths){
            path[p[0]].insert(p[1]);
            path[p[1]].insert(p[0]);
        }
        // vector<int> visited(N+1, 0);
        queue<int> next;
        for(int i=1; i<=N; i++){
            if(rets[i-1]) continue;
            next.push(i);
            while(next.size()){
                int cur = next.front();
                vector<int> color(5, 0);
                next.pop();
                for(int nx:path[cur]){
                    if(rets[nx-1] == 0){
                        next.push(nx);
                    }else
                        color[rets[nx-1]] = 1;
                }
                for(int i=1; i<5; ++i){
                    if(color[i] == 0){
                        rets[cur-1] = i;
                        break;
                    }
                }
            }
        }
        return rets;
    }
};

// Greedy O(N)
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ret(N, 0);
        vector<set<int>> mp(N+1);
        for(vector<int> p:paths){
            mp[p[0]].insert(p[1]);
            mp[p[1]].insert(p[0]);
        }
        for(int i=1; i<=N; i++){
            vector<int> color(5, 0);
            for(int nei:mp[i])
                color[ret[nei-1]] = 1;
            int j = 1;
            for(; color[j]!=0; ++j);
            ret[i-1] = j;
        }
        return ret;
    }
};