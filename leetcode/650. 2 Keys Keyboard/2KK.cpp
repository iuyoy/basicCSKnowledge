/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].
*/

// DP O( sigma(i:1~n/2){n/i} )<O(nlogn), O(n) 
class Solution {
public:
    int minSteps(int n) {
        int ret = n;
        vector<int>dp(n+1, n);
        dp[1] = 0;
        for(int i=1; i<=n/2; ++i)
            for(int j=2; j*i<=n; ++j)
                dp[j*i] = min(dp[i]+j, dp[j*i]);
        return dp[n];
    }
};
// Greedy O(sqrt(n)) O(1)
class Solution {
public:
    int minSteps(int n) {
        int ret = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            while (n%i == 0) {
                ret += i;
                n /= i;
            }
        }
        if (n > 1) ret += n;
        return ret;
    }
};