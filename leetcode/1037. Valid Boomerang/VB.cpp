/*
A boomerang is a set of 3 points that are all distinct and not in a straight
line.

Given a list of three points in the plane, return whether these points are a
boomerang.



Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false


Note:

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/

class Solution {
  public:
    bool isBoomerang(vector<vector<int>> &points) {
        int x1 = points[0][0], x2 = points[1][0], x3 = points[2][0];
        int y1 = points[0][1], y2 = points[1][1], y3 = points[2][1];
        int dx1 = x2 - x1, dx2 = x3 - x1;
        int dy1 = y2 - y1, dy2 = y3 - y1;
        return dy2 * dx1 != dx2 * dy1;
    }
};