/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/
class Solution {
public:
    // Math combination
    int countNumbersWithUniqueDigits(int n) {
        vector<int> tbl(min(n,10)+1, 1);
        int ret = 1;
        for (int i = 1; i <= min(n,10); i++){
            tbl[i] = tbl[i-1] * (i == 1? 9: (9-i+2));
            ret += tbl[i];
        }
        return ret;
    }
};
