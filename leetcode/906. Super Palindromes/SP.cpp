/*
Let's say a positive integer is a superpalindrome if it is a palindrome, and it
is also the square of a palindrome.

Now, given two positive integers L and R (represented as strings), return the
number of superpalindromes in the inclusive range [L, R].



Example 1:

Input: L = "4", R = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a
palindrome.


Note:

1 <= len(L) <= 18
1 <= len(R) <= 18
L and R are strings representing integers in the range [1, 10^18).
int(L) <= int(R)
*/
// generate result by brute, and 
#include <string>
class Solution {
  public:
    int superpalindromesInRange(string L, string R) {
        vector<int> allow(
            {1,         2,         3,         11,        22,        101,
             111,       121,       202,       212,       1001,      1111,
             2002,      10001,     10101,     10201,     11011,     11111,
             11211,     20002,     20102,     100001,    101101,    110011,
             111111,    200002,    1000001,   1001001,   1002001,   1010101,
             1011101,   1012101,   1100011,   1101011,   1102011,   1110111,
             1111111,   2000002,   2001002,   10000001,  10011001,  10100101,
             10111101,  11000011,  11011011,  11100111,  11111111,  20000002,
             100000001, 110000011, 100010001, 110010011, 100020001, 110020011,
             100101001, 110101011, 100111001, 110111011, 100121001, 101000101,
             111000111, 101010101, 111010111, 101020101, 101101101, 111101111,
             101111101, 111111111, 200000002, 200010002});
        long long l = stoll(L), r = stoll(R);
        int ret = 0;
        for (long long a : allow) {
            if (l <= a * a && a * a <= r)
                ret++;
        }
        return ret;
    }
};