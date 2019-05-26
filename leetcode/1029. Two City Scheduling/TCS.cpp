/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
*/


// Greedy O(nlogn) sort absolute differences between a and b
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> diff(n, vector<int>(3));
        for(int i=0; i<n; ++i){
            diff[i][0] = abs(costs[i][0]-costs[i][1]); // absolute difference
            diff[i][1] = i;// index
            diff[i][2] = costs[i][0] > costs[i][1];// which city to choose.
        }
        sort(diff.begin(), diff.end(), greater<vector<int>>());
        int ret = 0;
        int remain[2] = {n/2, n/2};
        for(auto d:diff){
            if(remain[d[2]]>0)
                ret += costs[d[1]][d[2]];
            else
                ret += costs[d[1]][1-d[2]];
            remain[d[2]] --;
        }
        return ret;
    }
};

// Greedy O(nlogn) sort differences between a and b
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ret = 0;
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
           return  a[0] - a[1] < b[0] - b[1];
        });
        // the front half of the sorted vector fly to A, the left fly to B
        for(int i=0; i<n/2; ++i)
            ret += costs[i][0] + costs[i+n/2][1];
        return ret;
    }
};

//DP O(n^2) from https://leetcode.com/problems/two-city-scheduling/discuss/278731/Java-DP-Easy-to-Understand
//dp[i][j] represents the cost when considering first (i + j) people in which i people assigned to city A and j people assigned to city B.
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        int dp[n+1][n+1];
        dp[0][0] = 0;
        for(int i=1; i<=n; ++i)
            dp[i][0] = dp[i-1][0] + costs[i-1][0];
        for(int i=1; i<=n; ++i)
            dp[0][i] = dp[0][i-1] + costs[i-1][1];
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                dp[i][j] = min(dp[i-1][j]+costs[i+j-1][0], dp[i][j-1]+costs[i+j-1][1]);
        return dp[n][n];
    }
};
/*
[[10,20],[30,200],[400,50],[30,20]]
[[20, 50], [30, 70]]
[[20, 50], [30, 60]]
[[20, 50], [30, 50]]
[[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
*/