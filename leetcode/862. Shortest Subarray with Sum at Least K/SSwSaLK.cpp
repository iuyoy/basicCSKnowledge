/*

Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3
 

Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9
*/
// Awesome solution
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solution/
// Slide Window O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size(), ret = n+1;
        vector<int> sum(ret);
        for(int i=0; i<n; ++i)
            sum[i+1] += A[i]+sum[i];
        // sum from A[i+1] to A[j] = sum[j] - sum[i]
        deque<int> dq;
        for(int i=0; i<=n; ++i){
            while(dq.size() && sum[dq.back()]>sum[i])
                dq.pop_back();
            while(dq.size() && sum[i] - sum[dq.front()] >= K){
                ret = min(ret, i - dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return ret<=n?ret:-1;
    }
};
/*
[1]
1
[1,2]
4
[2,-1,2]
3
[1,2,3,4,-5,4,7,4,-1,-1,-1,2]
11
[1,2,3,4,-5,4,7,4,-1,-1,-1,22]
10
[1,2,3,4,-5,4,7,4,-1,-1,-1,22]
20
[-28,81,-20,28,-29]
89
[-47,45,92,86,17,-22,77,62,-1,42]
180
*/