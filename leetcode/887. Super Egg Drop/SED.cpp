/*
You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000
*/

// DP O(NKlog(N))
// dp[n][k] means the move of N floors K eggs
// dp[n][k] = 1 + min( max(dp[n-i][k], dp[i-1][k-1] for i in range(1, n-1)))
// using binary search to find the closest pair.
const int INF = 0x3f3f3f3f;
int dp[10010][110];
class Solution {
  public:
    int superEggDrop(int K, int N) {
        int left, right, mid;
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=N; ++i) dp[i][1] = i;
        
        for(int j=2; j<=K; ++j)
            for(int i=1; i<=N; ++i){
                left = 1, right = i;
                while(left<right){
                    mid = (left+right)/2;
                    if(dp[i-mid][j] > dp[mid-1][j-1])
                        left = mid + 1;
                    else if(dp[i-mid][j]  < dp[mid-1][j-1])
                        right = mid ;
                    else 
                        break;
                }
                mid = (left+right)/2;
                dp[i][j] = 1 + max(dp[i-mid][j], dp[mid-1][j-1]);
            }
        return dp[N][K];
    }
};
// change the index meaning of DP, 有的时候可以把要求的结果当成DP的一个维度
// See also https://leetcode.com/problems/super-egg-drop/discuss/158974/C++JavaPython-2D-and-1D-DP-O(KlogN)
// and https://leetcode.com/problems/super-egg-drop/solution/
// 
/*
1
2
2 
6
3 
14
10
100
10
1000
100
10000
2
2
4
10000
*/