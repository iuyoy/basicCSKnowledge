/*
Given a string s, find the longest palindromic subsequence's length in s. You
may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

typedef vector<int> vi;
typedef vector<vi> vvi;

// DP O(n^2) O(n^2)
// dp[i][j] = longest palindrome subsequence of s[i to j].
// If s[i] == s[j], dp[i][j] = 2 + dp[i+1][j - 1]
// Else, dp[i][j] = max(dp[i+1][j], dp[i][j-1])
class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vvi dp(n, vi(n, 1));
        for (int i = 0; i < n - 1; ++i)
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 2;
        for (int i = 2; i < n; ++i)
            for (int j = i - 2; j >= 0; --j)
                if (s[j] == s[i])
                    dp[j][i] = 2 + dp[j + 1][i - 1];
                else
                    dp[j][i] = max(dp[j][i - 1], dp[j + 1][i]);
        return dp[0][n - 1];
    }
};

//DP advanced O(n^2) O(n)
class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vi dp(n, 1); // dp[j] means the max length from j to current i
        for (int i = 1; i < n; ++i) {
            int pre = dp[i]; //means j to i-1
            for (int j = i - 1; j >= 0; --j) {
                int tmp = dp[j];
                if (s[j] == s[i])
                    dp[j] = j < i - 1? pre + 2 : 2;
                else
                    dp[j] = max(dp[j + 1], dp[j]); 
                    // dp[j+1] is new means j+1 to i;
                pre = tmp;
            }
        }
        return dp[0];
    }
};