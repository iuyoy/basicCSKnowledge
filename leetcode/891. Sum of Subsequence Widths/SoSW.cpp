/*
Given an array of integers A, consider all non-empty subsequences of A.

For any sequence S, let the width of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A. 

As the answer may be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= 20000
*/

// DP by Math, O(nlogn)
// f(n) = 3f(n-1) - 2f(n-2) + (2^n-1)*A[n] - A[n-1]; 
const int mod = 1e9+7;
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        long last = 0, cur = 0, pow = 1;
        for(int i=1; i<n; ++i){
            long temp = cur;
            pow = (pow<<1)%mod;
            cur = 3*cur - last + mod + (A[i]-A[i-1])*(pow-1)%mod;
            cur %= mod;
            last = (2*temp)%mod;
        }
        return cur;
    }
};
// can get the expression of f(n);