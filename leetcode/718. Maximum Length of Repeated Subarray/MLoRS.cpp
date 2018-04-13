/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/
// DP with Hash O(m*n)
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> dp(A.size(), 0);
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i<A.size(); ++i)
            hash[A[i]].insert(hash[A[i]].begin(), i);
        int ret = 0;
        for(int index:hash[B[0]]){
            dp[index] = 1;
            ret = 1;
        }
        for(int i = 1; i<B.size(); ++i)
            for(int index:hash[B[i]]){
                dp[index] = (index>0 && A[index-1] == B[i-1])? dp[index-1]+1 : 1;
                ret = max(ret, dp[index]);
            }
        return ret;
    }
};
