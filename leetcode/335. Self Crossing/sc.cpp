/*
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:
Given x = [2, 1, 1, 2],
?????
?   ?
???????>
    ?

Return true (self crossing)
Example 2:
Given x = [1, 2, 3, 4],
????????
?      ?
?
?
?????????????>

Return false (not self crossing)
Example 3:
Given x = [1, 1, 1, 1],
?????
?   ?
?????>

Return true (self crossing)
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

//Math O(n) O(1)
//  outer or inner spire and check when transfer from outer to inner.
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        const int n = x.size();
        if(n<3)
            return false;
        // outer spire
        int i = 2;
        while(i<n && x[i]>x[i-2])
            ++i;

        if (x[i] >= x[i - 2] - x[i - 4]){
            x[i - 1] -= x[i - 3];
        }
        ++i;
        while(i<n && x[i]<x[i-2])
            ++i;
        return !(i >= n);
    }
};
