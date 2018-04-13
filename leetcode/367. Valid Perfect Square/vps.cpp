/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

*/
// Binary Search O(logn)
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 0) return false;
        int l = 1, r = num, mid = 0, pro = 0;
        while(l<=r){
            mid = (l+r)/2;
            pro = num / mid;
            if(pro == mid && mid * mid == num)
                return true;
            if(pro < mid)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};
