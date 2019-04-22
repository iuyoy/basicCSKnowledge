/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
// DP by every number, O(n^2) TLE
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; ++i){
            int a = sqrt(i);
            if(a*a == i) dp[i] = 1;
            else
                for(int j=1;j<=i/2; ++j)
                    dp[i] = min(dp[i], dp[j]+dp[i-j]);
        }
        return dp[n];
    }
};
//Dp by every square number O(n*sqrt(n))
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        dp[1]=1;
        vector<int> squares({0,1});
        int next = 2;
        for(int i=2; i<=n; ++i){
            if(i == next*next ){
                dp[i] = 1;
                squares.push_back(next*next);
                ++next;
            }else{
                for(int j=1;j<next;++j){
                    dp[i] = min(dp[i], dp[i%squares[j]] + i/squares[j]);
                }
            }
        }
        return dp[n];
    }
};

//Dp by every square number advanced, O(n*sqrt(n))
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        dp[1]=1;
        for(int i=2; i<=n; ++i){
            for(int j=1;j*j<=i;++j){
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
};
/*
1
2
3
4
5
6
7
8
9
10
11
12
13
8441
*/