/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.
*/

// bt O(ret)
class Solution {
public:
    int ret;
    int N;
    void bt(vector<int>& visited, int idx){
        if(idx > N) ++ret;
        for(int i=1; i<=N; ++i){
            if(visited[i] == 0 && (idx%i==0 || i%idx == 0)){
                visited[i] = 1;
                bt(visited, idx+1);
                visited[i] = 0;
            }
        }
    }
    int countArrangement(int N) {
        this->N = N;
        ret = 0;
        vector<int> visited(N+1, 0);
        bt(visited, 1);
        return ret;
    }
};

// DP O(2^N)
class Solution {
public:
    vector<int> dp;
    int dfs(int cur, int idx){
        if(dp[cur] == -1){
            dp[cur] = 0;
            for(int i=0; (1<<i) <= cur; i++)
                if(cur&(1<<i) && (idx % (i+1) ==0 || (i+1)%idx == 0))
                    dp[cur] += dfs(cur ^ (1<<i) , idx-1);
        }
        return dp[cur];
    }
    int countArrangement(int N) {
        dp.assign(1<<N, -1);
        dp[0] = 1;
        return dfs((1<<N)-1, N);
    }
};