/*
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Note:

1 <= N <= 1000
*/

// DP 遍历法
class Solution {
public:
    bool divisorGame(int N) {
        if(N==1) return false;
        vector<int> dp(N+1, 0);
        dp[2]=1;
        for(int n = 3; n<=N; ++n){
            for(int x = 1; x<n; ++x){
                if(n%x == 0)
                    dp[n] |= !dp[n-x];
            }
        }
        return dp[N];
    }
};

// DP 筛法
class Solution {
public:
    bool divisorGame(int N) {
        if(N==1) return false;
        vector<int> dp(N+1, 0);
        dp[2]=1;
        for(int gap=1;gap<=N/2;++gap)
            for(int cur = gap+gap; cur <= N; cur += gap)
                dp[cur] |= !dp[cur-gap];
        return dp[N];
    }
};

// Math 偶数为先手， 奇数为后手
// 归纳法可证 
// 奇数的因数都是奇数，奇数减奇数是偶数，必然后手胜
// 偶数减1为奇数，必存在先手胜
class Solution {
public:
    bool divisorGame(int N) {
        return N%2==0;
    }
};
