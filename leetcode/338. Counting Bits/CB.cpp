/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

//DP O(n) O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1);
        ret[0] = 0;
        int i = 1, j = 0;
        int sign = 1;

        while(i<=num){
            ret[i++] = ret[j++]+1;
            if(j==sign){
                sign <<= 1;
                j = 0;
            }   
        }
        return ret;
    }
};

// the result of i = 1 + the result of i&(i-1)
// i&(i- 1) means clear the last 1 in i. 
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};