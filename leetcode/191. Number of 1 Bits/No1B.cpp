/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
Example 2:

Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000
*/
//count - divide by 2 O(n) n is the bit of num
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            ret += n&1;
            n >>= 1;
        }
        return ret;
    }
};

// count - clear last 1 O(k) k is the number of 1 occurs in num. 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            n &= (n-1);
            ret ++;
        }
        return ret;
    }
};