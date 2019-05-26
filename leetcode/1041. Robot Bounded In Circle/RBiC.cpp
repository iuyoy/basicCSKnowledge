/*
On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinetely.
Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Note:

1 <= instructions.length <= 100
instructions[i] is in {'G', 'L', 'R'}
*/

// O(n) 
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dirs = {{0,1}, {-1,0}, {0,-1}, {1,0}};
        vector<int> pos = {0, 0};
        int d = 0;
        // at most 4 times I guess, but I set it to 100.
        for(int i=0; i<=100; ++i){
            for(char c:instructions){
                if(c == 'G'){
                    pos[0] += dirs[d][0];
                    pos[1] += dirs[d][1];
                }else if(c == 'L')
                    d = (d+1)%4;
                else
                    d = (d+3)%4;
            }
            if(pos[0] == 0 && pos[1] == 0)
                return true;
        }
        return false;
    }
};