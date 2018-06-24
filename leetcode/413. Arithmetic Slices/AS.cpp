/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

// BF O(n^3) or O(n^2), O(1)
// DP O(n) , O(n) or O(1)
// Count and calculate O(n), O(1)
class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& A) {
        const int n = A.size();
        if(n<3)
            return 0;
        int c = 0;
        int minus = A[1] - A[0];
        int ret = 0;
        for(int i = 2;i<n;++i){
            if(A[i]-A[i-1] == minus)
                ++c;
            else{
                ret += (1+c)*c/2;//may overflow
                minus = A[i] - A[i-1];
                c = 0;
            }
        }
        ret += (1+c)*c/2;//may overflow
        return ret;
    }
};