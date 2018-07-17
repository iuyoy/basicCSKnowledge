/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
  public:
    int maxPoints(vector<Point> &points) {
        unordered_map<int, vector<vector<long>>> umap;
        int n = points.size();
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            duplicate = 2;
            for (int j = 0; j < i; ++j) {
                long a = points[i].x - points[j].x,
                     b = points[i].y - points[j].y;
                if (a == 0 && b == 0) {
                    for (auto &v : umap[j])
                        ++v[2];
                    start[j]++;
                } else {
                    auto it = umap[j].begin();
                    for (; it != umap[j].end(); ++it)
                        if ((*it)[0] * b == (*it)[1] * a) {
                            ++(*it)[2];
                            break;
                        }
                    if (it == umap[j].end())
                        umap[j].push_back({a, b, start[j]});
                }
            }
        }
        long ret = 0;
        for (long s : start)
            ret = max(ret, s - 1);
        for (int i = 0; i < n; ++i)
            for (auto v : umap[i])
                ret = max(ret, v[2]);
        return ret;
    }
};

/*
[[1,1],[2,2],[3,3]]
[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
[[0,0]]
[[0,0],[1,65536],[65536,0]]
[[0,9],[138,429],[115,359],[115,359],[-30,-102],[230,709],[-150,-686],[-135,-613],[-60,-248],[-161,-481],[207,639],[23,79],[-230,-691],[-115,-341],[92,289],[60,336],[-105,-467],[135,701],[-90,-394],[-184,-551],[150,774]]
[[0,0],[0,0],[1,1],[2,2]]
[[0,0],[0,0]]
[[0,0],[1,1],[0,0]]
[[1,1],[1,1],[1,1]]
*/