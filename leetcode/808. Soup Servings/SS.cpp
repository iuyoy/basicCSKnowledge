/*
There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B
Serve 75 ml of soup A and 25 ml of soup B
Serve 50 ml of soup A and 50 ml of soup B
Serve 25 ml of soup A and 75 ml of soup B
When we serve some soup, we give it to someone and we no longer have it.  Each turn, we will choose from the four operations with equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as we can.  We stop once we no longer have some quantity of both types of soup.

Note that we do not have the operation where all 100 ml's of soup B are used first.  

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time.

 

Example:
Input: N = 50
Output: 0.625
Explanation: 
If we choose the first two operations, A will become empty first. For the third operation, A and B will become empty at the same time. For the fourth operation, B will become empty first. So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.

Notes:

0 <= N <= 10^9. 
Answers within 10^-6 of the true value will be accepted as correct.
*/

// DP
class Solution {
private:
    vector<vector<double>> dp;    
    double go(int i, int j, int m, int n){
        if(i>m)
            if(j>n)
                return 0.25*dp[i-m][j-n];
            else
                return 0.0;
        else
            if(j>n)
                return 0.25;
            else
                return 0.125;
    }
public:
    double soupServings(int N) {
        if(N>=5000)
            return 1.0;
        if(N==0)
            return 0.5;
        int n = (N-1)/25 + 2;
        dp = vector<vector<double>>(n, vector<double>(n));
        for(int i = 1; i<n; ++i){
            for(int j = 1; j<n; ++j){
                dp[i][j] = go(i,j,4,0) + go(i,j,3,1) + go(i,j,2,2) + go(i,j,1,3);
            }
        }
        return dp[n-1][n-1];
    }
    
};