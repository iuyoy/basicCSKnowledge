/*
A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.

 

Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
Example 2:

Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
Example 3:

Input: "00011000"
Output: 2
Explanation: We flip to get 00000000.
 

Note:

1 <= S.length <= 20000
S only consists of '0' and '1' characters.
*/
// DP O(n)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        int ret = n;
        int count_1 = 0, count_0 = 0;
        for(char c:S)
            if(c == '1') count_1 ++;
        int i = 0;
        for(char c:S){
            ret = min(ret, n - count_0 - count_1);
            if(c == '0') count_0 ++;
            else if(c == '1') count_1 --;
        }
        ret = min(ret, n - count_0 - count_1);
        return ret;
    }
};