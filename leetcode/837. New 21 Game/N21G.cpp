/*
Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points, and draws numbers while she has less than K points.  During each draw, she gains an integer number of points randomly from the range [1, W], where W is an integer.  Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets K or more points.  What is the probability that she has N or less points?

Example 1:

Input: N = 10, K = 1, W = 10
Output: 1.00000
Explanation:  Alice gets a single card, then stops.
Example 2:

Input: N = 6, K = 1, W = 10
Output: 0.60000
Explanation:  Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.
Example 3:

Input: N = 21, K = 17, W = 10
Output: 0.73278
Note:

0 <= K <= N <= 10000
1 <= W <= 10000
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
The judging time limit has been reduced for this question.
*/
// DP on times O(K*K*W*W) TLE
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0 || N>=K+W-1) return 1.0;
        if(N<K) return 0.0;
        double base = 1.0/W;
        vector<double> dp(N+1);
        for(int i=1;i<=min(W,N);++i) dp[i] = base;
        for(int i=1;i<K;++i){
            for(int j=min(i*W, K-1); j>=i;--j){
                for(int k=1;k<=W && k+j<=N;++k) 
                    dp[k+j] += dp[j]*base;
                dp[j] = 0;
            }  
        }
        double ret = 0;
        for(int i=K; i<=N; ++i)
            ret += dp[i];
        return ret;
    }
};


// DP step by step, O(N*W) TLE
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0 || N>=K+W-1) return 1.0;
        if(N<K) return 0.0;
        double base = 1.0/W;
        vector<double> dp(N+1);
        for(int i=1;i<=min(W,N);++i) dp[i] = base;
        for(int i=1;i<=N;++i){
            for(int j=min(W,i-1); j>=max(1, i-K+1); --j)
                dp[i] += dp[i-j]*base;
        }
        double ret = 0;
        for(int i=K; i<=N; ++i){
            ret += dp[i];
        }
        return ret;
    }
};

//DP optimized from above method O(N) 
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0 || N>=K+W-1) return 1.0;
        if(N<K) return 0.0;
        double base = 1.0/W;
        vector<double> dp(N+1);
        for(int i=1;i<=min(W,N);++i) dp[i] = base;
        for(int i=2;i<=N;++i){
            if(i>W+1)
                dp[i] = (dp[min(i-1, K-1)]-dp[i-W-1])*base + dp[i-1];
            else
                dp[i] += dp[min(i-1, K-1)]*base + dp[i-1];
        }
        return dp[N]-dp[K-1];
    }
};
/*
0
0
2
1
1
10
2
2
10
3
3
10
11
11
10
11
10
10
12
11
10
*/