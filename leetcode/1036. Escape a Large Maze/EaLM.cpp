/*
In a 1 million by 1 million grid, the coordinates of each grid square are (x, y) with 0 <= x, y < 10^6.

We start at the source square and want to reach the target square.  Each move, we can walk to a 4-directionally adjacent square in the grid that isn't in the given list of blocked squares.

Return true if and only if it is possible to reach the target square through a sequence of moves.

 

Example 1:

Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
Output: false
Explanation: 
The target square is inaccessible starting from the source square, because we can't walk outside the grid.
Example 2:

Input: blocked = [], source = [0,0], target = [999999,999999]
Output: true
Explanation: 
Because there are no blocked cells, it's possible to reach the target square.
 

Note:

0 <= blocked.length <= 200
blocked[i].length == 2
0 <= blocked[i][j] < 10^6
source.length == target.length == 2
0 <= source[i][j], target[i][j] < 10^6
source != target
*/

// limited BFS O(20000*2)
class Solution {
public:
    vector<vector<int>> dirs;
    set<pair<int, int>> blk;
    bool bfs(int& si, int& sj, int& x, int& y){
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        visited.insert({si,sj});
        q.push({si, sj});
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            if(i == x && j == y) return true;
            if(visited.size() > 20000) return true;
            q.pop();
            for(vector<int> dir:dirs){
                int i2 = i+dir[0], j2 = j+dir[1];
                if(0<=i2 && i2<1000000 && 0<=j2 && j2<1000000 && visited.count({i2,j2}) == 0 && blk.count({i2, j2}) ==0){
                    visited.insert({i2,j2});
                    q.push({i2, j2});
                }
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(vector<int> b:blocked)
            blk.insert({b[0], b[1]});
        if(bfs(source[0], source[1], target[0], target[1]) && bfs(target[0], target[1], source[0], source[1]))
            return true;
        return false;
    }
};

//limited DFS, Stackoverflow
class Solution {
public:
    vector<vector<int>> dirs;
    set<pair<int, int>> blk;
    bool dfs(int i, int j, int& x, int& y, set<pair<int, int>>& visited){
        if(i<0 || i>=1e6 || j<0 || j>=1e6 || visited.count({i,j}) || blk.count({i,j})) return false;
        // if(visited.size()%200==0)
        // cout<<visited.size() << " ";
        if(visited.size() > 20000) return true;
        if(i == x && j == y) return true;
        visited.insert({i,j});
        return dfs(i+1,j,);
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(vector<int> b:blocked)
            blk.insert({b[0], b[1]});
        set<pair<int, int>> v1, v2;
        if(dfs(source[0], source[1], target[0], target[1], v1) && dfs(target[0], target[1], source[0], source[1], v2))
            return true;
        cout << endl;
        return false;
    }
};

/*
[[0,1],[1,0]]
[0,0]
[0,2]
[]
[0,0]
[999999,999999]
[[100005,100073],[100006,100074],[100007,100075],[100008,100076],[100009,100077],[100010,100078],[100011,100079],[100012,100080],[100013,100081],[100014,100082],[100015,100083],[100016,100084],[100017,100085],[100018,100086],[100019,100087],[100020,100088],[100021,100089],[100022,100090],[100023,100091],[100024,100092],[100025,100091],[100026,100090],[100027,100089],[100028,100088],[100029,100087],[100030,100086],[100031,100085],[100032,100084],[100033,100083],[100034,100082],[100035,100081],[100036,100080],[100037,100079],[100038,100078],[100039,100077],[100040,100076],[100041,100075],[100042,100074],[100043,100073],[100044,100072],[100043,100071],[100042,100070],[100041,100069],[100040,100068],[100039,100067],[100038,100066],[100037,100065],[100036,100064],[100035,100063],[100034,100062],[100033,100061],[100032,100060],[100031,100059],[100030,100058],[100029,100057],[100028,100056],[100027,100055],[100026,100054],[100025,100053],[100024,100052],[100023,100053],[100022,100054],[100021,100055],[100020,100056],[100019,100057],[100018,100058],[100017,100059],[100016,100060],[100015,100061],[100014,100062],[100013,100063],[100012,100064],[100011,100065],[100010,100066],[100009,100067],[100008,100068],[100007,100069],[100006,100070],[100005,100071]]
[100024,100072]
[999994,999990]
[[100059,100063],[100060,100064],[100061,100065],[100062,100066],[100063,100067],[100064,100068],[100065,100069],[100066,100070],[100067,100071],[100068,100072],[100069,100073],[100070,100074],[100071,100075],[100072,100076],[100073,100077],[100074,100078],[100075,100079],[100076,100080],[100077,100081],[100078,100082],[100079,100083],[100080,100082],[100081,100081],[100082,100080],[100083,100079],[100084,100078],[100085,100077],[100086,100076],[100087,100075],[100088,100074],[100089,100073],[100090,100072],[100091,100071],[100092,100070],[100093,100069],[100094,100068],[100095,100067],[100096,100066],[100097,100065],[100098,100064],[100099,100063],[100098,100062],[100097,100061],[100096,100060],[100095,100059],[100094,100058],[100093,100057],[100092,100056],[100091,100055],[100090,100054],[100089,100053],[100088,100052],[100087,100051],[100086,100050],[100085,100049],[100084,100048],[100083,100047],[100082,100046],[100081,100045],[100080,100044],[100079,100043],[100078,100044],[100077,100045],[100076,100046],[100075,100047],[100074,100048],[100073,100049],[100072,100050],[100071,100051],[100070,100052],[100069,100053],[100068,100054],[100067,100055],[100066,100056],[100065,100057],[100064,100058],[100063,100059],[100062,100060],[100061,100061],[100060,100062]]
[100079,100063]
[999948,999967]
*/

#define m 1000000

float direct(vector<int>& i,vector<int>& j,vector<int>& k)     //计算叉积
{
	return (k[0]-i[0])*(j[1]-i[1])-(j[0]-i[0])*(k[1]-i[1]);
}
 
int onsegment(vector<int>& a,vector<int>& b,vector<int>& c)   //共线时，判断点是否落在线段上   
{
	float minx=min(a[0],b[0]);
	float maxx=max(a[0],b[0]);
	float miny=min(a[1],b[1]);
	float maxy=max(a[1],b[1]);
	return c[0]>=minx&&c[0]<=maxx&&c[1]>=miny&&c[1]<=maxy;
}
int cross(vector<int>& p1,vector<int>& q1,vector<int>& p2,vector<int>& q2)
{
    float d1=direct(p2,q2,p1);        
    float d2=direct(p2,q2,q1);
    float d3=direct(p1,q1,p2);
    float d4=direct(p1,q1,q2);
    if(d1*d2<0&&d3*d4<0)
        return true;
    else if(d1==0&&onsegment(p2,q2,p1))
        return true;
    else if(d2==0&&onsegment(p2,q2,q1))
        return true;
    else if(d3==0&&onsegment(p1,q1,p2))
        return true;
    else if(d4==0&&onsegment(p1,q1,q2))
        return true;
    return false;
}
// bool cross(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d)
// {
//     //快速排斥实验
//     if ((a[0] > b[0] ? a[0] : b[0]) < (c[0] < d[0] ? c[0] : d[0]) ||
//         (a[1] > b[1] ? a[1] : b[1]) < (c[1] < d[1] ? c[1] : d[1]) ||
//         (c[0] > d[0] ? c[0] : d[0]) < (a[0] < b[0] ? a[0] : b[0]) ||
//         (c[1] > d[1] ? c[1] : d[1]) < (a[1] < b[1] ? a[1] : b[1]))
//     {
//         return false;
//     }
//     //跨立实验
//     if ((((a[0] - c[0])*(d[1] - c[1]) - (a[1] - c[1])*(d[0] - c[0]))*
//         ((b[0] - c[0])*(d[1] - c[1]) - (b[1] - c[1])*(d[0] - c[0]))) > 0 ||
//         (((c[0] - a[0])*(b[1] - a[1]) - (c[1] - a[1])*(b[0] - a[0]))*
//         ((d[0] - a[0])*(b[1] - a[1]) - (d[1] - a[1])*(b[0] - a[0]))) > 0)
//     {
//         return false;
//     }
//     return true;
// }
class Solution {
public:
   
    unordered_map<int, unordered_map<int, int>> blk;
    vector<vector<int>> dirs;
    vector<int> s, t;
    bool check(vector<vector<int>>& points){
        for(int i = 0; i+1<points.size(); ++i)
            if(cross(points[i], points[i+1], s, t))
                return false;
        return true;
    }
    bool dfs(vector<vector<int>>& points, int i, int j){
        blk[i][j] = 2;
        points.push_back({i, j});
        if(i == 0 || i == m-1 || j == 0 || j == m-1){
            int idx = 0;
            for(; idx<points.size(); ++idx){
                if(points[idx][0] == 0 || points[idx][1] == 0 || points[idx][0] == m-1 || points[idx][1] == m-1) break;
            }
            for(; idx<points.size(); ++idx)
                for(int i = 0; i+1<points.size(); ++i)
                    if(cross(points[i], points[i+1], s, t))
                        return false;
        }
        for(vector<int> dir:dirs){
            int x = i+dir[0], y = j + dir[1];
            if(0<=x && x<m && 0<=y && y<m){
                if(blk[x][y] == 1){
                    if(dfs(points, x, y) == false)
                        return false;
                }else{
                    points.push_back({x, y});
                    int idx = 0;
                    for(; idx<points.size(); ++idx){
                        if(points[idx][0] == x && points[idx][1] == y) break;
                    }
                    for(; idx<points.size(); ++idx)
                        for(int i = 0; i+1<points.size(); ++i)
                            if(cross(points[i], points[i+1], s, t))
                                return false;
                    points.pop_back();
                }
            }
        }
        blk[i][j] = 1;
        points.pop_back();
        return true;
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        dirs = {{-1, 1}, {0, 1}, {1,1},{-1,0},{1,0},{-1,-1},{0,-1},{1,-1}};
        s = source;
        t = target;

        for(auto block:blocked){
            blk[block[0]][block[1]] = 1;
        }
        // int i, j;
        vector<vector<int>> points;
        for(auto block:blocked){
            int i = block[0], j = block[1];            
            if(blk[i][j] == 2) continue;
            if(dfs(points, i, j) == false)
                return false;
        }
        return true;
    }
};