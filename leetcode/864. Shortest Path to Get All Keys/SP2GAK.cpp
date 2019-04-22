/*
We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is
the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.

We start at the starting point, and one move consists of walking one space in
one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into
a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless
we have the corresponding key.

For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of
the first K letters of the English alphabet in the grid.  This means that there
is exactly one key for each lock, and one lock for each key; and also that the
letters used to represent the keys and locks were chosen in the same order as
the English alphabet.

Return the lowest number of moves to acquire all keys.  If it's impossible,
return -1.



Example 1:

Input: ["@.a.#","###.#","b.A.B"]
Output: 8
Example 2:

Input: ["@..aA","..B#.","....b"]
Output: 6


Note:

1 <= grid.length <= 30
1 <= grid[0].length <= 30
grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
The number of keys is in [1, 6].  Each key has a different letter and opens
exactly one lock.
*/

// BFS with key status recorded
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
struct location {
    int i, j, key;
    location(int i, int j, int key) {
        this->i = i;
        this->j = j;
        this->key = key;
    }
};
class Solution {
  public:
    int shortestPathAllKeys(vector<string> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int keys = 0, x = 0, y = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@')
                    x = i, y = j;
                if ('a' <= grid[i][j] && grid[i][j] <= 'f')
                    ++keys;
            }
        keys = (1 << keys);
        vvvi cost(m, vvi(n, vi(keys, INT_MAX)));
        cost[x][y][0] = 0;
        queue<location> q({location(x, y, 0)});
        vvi dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ret = INT_MAX;
        while (q.size()) {
            auto loc = q.front();
            q.pop();
            // cout<<loc.i<<" "<<loc.j<<" "<<loc.key<<endl;
            for (vi dir : dirs) {
                location next(loc.i + dir[0], loc.j + dir[1], loc.key);
                if (0 <= next.i && next.i < m && 0 <= next.j && next.j < n) {
                    if ('a' <= grid[next.i][next.j] &&
                        grid[next.i][next.j] <= 'f') {
                        next.key |= (1 << grid[next.i][next.j] - 'a');
                        if (next.key == keys - 1)
                            ret = min(ret, cost[loc.i][loc.j][loc.key] + 1);
                    }
                    if (next.key < keys - 1 && grid[next.i][next.j] != '#' &&
                        (('A' > grid[next.i][next.j] || grid[next.i][next.j] > 'F') || (next.key >> (grid[next.i][next.j] - 'A')) & 1 == 1) &&
                        cost[next.i][next.j][next.key] > 1 + cost[loc.i][loc.j][loc.key]) {
                        cost[next.i][next.j][next.key] = cost[loc.i][loc.j][loc.key] + 1;
                        q.push(next);
                    }
                }
            }
        }
        if (ret == INT_MAX)
            return -1;
        return ret;
    }
};

//更加好
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int keys = 0, ret = 0;
        queue<vector<int>> q;
        vvvb visited(m, vvb(n, vb(1<<6, 0)));
        
        for(int i=0;i<m; ++i)
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == '@') {
                    visited[i][j][0] = 1;
                    q.push({i, j, 0});
                }
                if('a' <= grid[i][j] && grid[i][j] <= 'f') ++keys;
            }
        keys = (1<<keys);
        vvi dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(q.size()){
            for(int i=q.size(); i>0; --i){
                auto top = q.front();
                q.pop();
                for(vi dir:dirs){
                    int x = top[0]+dir[0], y = top[1]+dir[1], key = top[2];
                    if(0<= x && x<m && 0<=y && y<n){
                        if('a' <= grid[x][y] && grid[x][y] <= 'f'){
                            key |= (1<< (grid[x][y] - 'a'));
                            if(key == keys - 1)
                                return ret+1;
                        }else if('A' <= grid[x][y] && grid[x][y] <= 'F')
                            if(((key >> (grid[x][y] - 'A')) & 1) == 0)
                                continue;
                        if(grid[x][y] != '#' && visited[x][y][key] == 0){
                            visited[x][y][key] = 1;
                            q.push({x, y, key});
                        }
                    }
                }
            }
            ++ret;
        }
        return -1;
    }
};
/*
["@.a.#","###.#","b.A.B"]
["@..aA","..B#.","....b"]
["@A","#a"]
*/