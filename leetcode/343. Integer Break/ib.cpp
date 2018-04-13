/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
//DP O(n^2) O(n)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 0;
        for(int i = 2;i<=n;++i){
            for(int j = 0;j<i;++j)
                dp[i] = max(dp[i], max(dp[j], j) * max(dp[i-j], i-j));
        }
        return dp[n];
    }
};
