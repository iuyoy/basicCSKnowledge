/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
*/
// Kadane algorithm O(n)
// Find the max and min sum of subarray withou circle - lg, sm
// The result is the max(lg, sum of A-sm)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int cur_lg = A[0], cur_sm=A[0];
        int lg = cur_lg, sm=cur_sm;
        bool flag = false; 
        int sum;
        // A flag to mark if idx 0 is the start of the least sum.
        for(int i=1;i<A.size();++i){
            if(cur_lg<0)
                cur_lg = 0;
            if(cur_sm>0){
                cur_sm = 0;
                flag = true;
            }
            cur_lg += A[i];
            cur_sm += A[i];
            lg = max(lg, cur_lg);
            // exclude the sum of whole array.
            if(flag || i!=A.size()-1)
                sm = min(sm, cur_sm);
            sum += A[i];
        }

        return max(lg, sum-sm);
    }
};