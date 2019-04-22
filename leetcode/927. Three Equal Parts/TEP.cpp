/*
Given an array A of 0s and 1s, divide the array into 3 non-empty parts such that
all of these parts represent the same binary value.

If it is possible, return any [i, j] with i+1 < j, such that:

A[0], A[1], ..., A[i] is the first part;
A[i+1], A[i+2], ..., A[j-1] is the second part, and
A[j], A[j+1], ..., A[A.length - 1] is the third part.
All three parts have equal binary value.
If it is not possible, return [-1, -1].

Note that the entire part is used when considering what binary value it
represents.  For example, [1,1,0] represents 6 in decimal, not 3.  Also, leading
zeros are allowed, so [0,1,1] and [1,1] represent the same value.



Example 1:

Input: [1,0,1,0,1]
Output: [0,3]
Example 2:

Input: [1,1,0,1,1]
Output: [-1,-1]


Note:

3 <= A.length <= 30000
A[i] == 0 or A[i] == 1
*/

// Construct split and judge. O(n)
// counts of 1 in these three parts should be same.
// counts of continuous zeor in the tail of these three parts should be same too.
class Solution {
  public:
    vector<int> threeEqualParts(vector<int> &A) {
        int n = A.size();
        int count_1 = 0;
        for (int a : A)
            if (a == 1)
                count_1++;
        if (count_1 % 3 != 0)
            return {-1, -1};
        if (count_1 == 0)
            return {0, n - 1};
        int start_l = -1, end_l = -1;
        int start_r = -1, end_r = -1;
        int count_1_ag = 0;
        count_1 /= 3;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1)
                count_1_ag++;
            if (count_1_ag == count_1) {
                if (start_l == -1)
                    start_l = i;
                end_l = i;
            } else if (count_1_ag == 2 * count_1) {
                if (start_r == -1)
                    start_r = i + 1;
                end_r = i + 1;
            }
        }
        int count_0 = 0;
        for (int i = n - 1; A[i] == 0; --i, ++count_0);
        start_l += count_0;
        start_r += count_0;
        // cout<<start_l << end_l << start_r<<end_r<<endl;
        if (start_r <= end_r && start_l <= end_l) {
            for (int i = 0, l = start_l, m = start_r - 1, r = n - 1;
                 i < count_1; --l, --m, --r) {
                if (A[l] != A[r] || A[r] != A[m])
                    return {-1, -1};
                if (A[l] == 1)
                    ++i;
            }
            return {start_l, start_r};
        }
        return {-1, -1};
    }
};
/*
[1,0,1,0,1]
[1,1,0,1,1]
[1,0,1,0,1,0]
[1,0,0,1,0,0,1]
[1,0,0,1,0,0,1,0,0]
[1,0,1,0,1,0,0]
*/