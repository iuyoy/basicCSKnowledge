/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
Seen this question in a real interview before?  

*/
// DP O(n^2) 
// Choose number as root every one.
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        dp[0] = 1;
        for(int i=1; i<=n; ++i)
            for(int j=0; j<i; ++j)
                dp[i] += dp[j]*dp[i-j-1];
        return dp[n];
    }
};
//C = C * 2 * (2 * i + 1) / (i + 2); 通项公式