/*
We are given S, a length n string of characters from the set {'D', 'I'}. (These letters stand for "decreasing" and "increasing".)

A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0, 1, ..., n}, such that for all i:

If S[i] == 'D', then P[i] > P[i+1], and;
If S[i] == 'I', then P[i] < P[i+1].
How many valid permutations are there?  Since the answer may be large, return your answer modulo 10^9 + 7.

 

Example 1:

Input: "DID"
Output: 5
Explanation: 
The 5 valid permutations of (0, 1, 2, 3) are:
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
 

Note:

1 <= S.length <= 200
S consists only of characters from the set {'D', 'I'}.
*/

typedef vector<long> vl;
typedef vector<vl> vvl;
long m = 1e9+7;

// DP by rule O(N^3)
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size();
        vvl dp(n+1, vl(n+1, 0));
        vvl C(n+1, vl(n+1, 1));
        // Calculate numbers of combination
        for(int i=0; i<=n; ++i){C[0][i] = 0;C[i][0] = 1; dp[i][i] = 1;}
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % m;
        for(int len = 1; len<=n; ++len){
            for(int i = 0; i+len<=n; ++i){
                int end = i+len;
                for(int j = i; j<=end; ++j){
                    if((j==i && S[j]=='D'))
                        dp[i][end] = ((C[len][j-i]*dp[i+1][end])%m + dp[i][end]) %m;
                    else if(j==end && S[j-1] == 'I')
                        dp[i][end] = ((C[len][end-j]*dp[i][end-1])%m + dp[i][end]) %m;
                    else if(S[j-1] == 'I' && S[j] == 'D')
                        dp[i][end] = ( ( ( (dp[i][j-1]*dp[j+1][end]) %m)*C[len][j-i] )%m + dp[i][end] )%m;
                }
            }
        }
        return dp[0][n];
    }
};

// more explanations in https://leetcode.com/problems/valid-permutations-for-di-sequence/discuss/168612/Top-down-with-Memo-greater-Bottom-up-DP-greater-N3-DP-greater-N2-DP-greater-O(N)-space
/*
"DID"
"DIDIDIDID"
"DIDIDIDIDDIDIDIDID"
"DIDIDIDIDDIDIDIDIDDIDIDIDID"
"DIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDID"
"DIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDDIDIDIDIDI"
*/