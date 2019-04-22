/*
Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

 

Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]
 

Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/
// reduce the intersect section
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int sm = A[0] - K, lg = A[0] + K;
        for(int i=1; i<A.size(); ++i){
            sm = max(sm, A[i]-K);
            lg = min(lg, A[i]+K);
        }
        return sm<lg?0:sm-lg;
    }
};

// improvement
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int sm = INT_MIN, lg = INT_MAX;
        for(int a:A){
            sm = max(sm, a);
            lg = min(lg, a);
        }
        return max(0, sm-lg-K-K);
    }
};