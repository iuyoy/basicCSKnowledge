/*
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 

Example 1:

Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10]
 

Note:

1 <= K <= A.length <= 500
0 <= A[i] <= 10^6
*/

// DP O(nk)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n+1, 0);
        for(int i=0; i<n; ++i){
            int top = A[i];
            for(int j=1; j<=K && i+1-j>=0; ++j){
                top = max(top, A[i+1-j]);
                dp[i+1] = max(dp[i+1], top*j + dp[i+1-j]);
            }
        }
        return dp[n];
    }
};