/*
Given an array of integers A, find the sum of min(B), where B ranges over every
(contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.



Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2],
[1,2,4], [3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.


Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
*/
// DP and stack
typedef vector<int> vi;
int m = 1e9 + 7;
class Solution {
  public:
    int sumSubarrayMins(vector<int> &A) {
        int n = A.size();
        int cur = A[0];
        stack<vector<int>> s({{A[0], 1, A[0]}});// cur small number, count, the sum of above sequences.
        for (int i = 1; i < n; ++i) {
            vector<int> next({A[i], 1, A[i]});
            while (s.size() && s.top()[0] >= next[0]) {
                next[1] += s.top()[1];
                s.pop();
            }
            next[2] = next[0] * next[1];
            if (s.size()) next[2] += s.top()[2];
            s.push(next);
            cur += next[2];
            cur %= m;
        }
        return cur;
    }
};