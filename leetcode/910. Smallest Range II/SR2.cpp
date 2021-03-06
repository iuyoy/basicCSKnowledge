/*
Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

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
Output: 3
Explanation: B = [4,6,3]
 

Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/

// See solution and discussion.
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        if(n==1) return 0;
        sort(A.begin(), A.end());
        int ret = A.back()-A.front();
        for(int i=0; i<n-1; ++i){
            int high = max(A.back()-K, A[i]+K);
            int low = min(A.front()+K, A[i+1]-K);
            ret = min(ret, high-low);
        }
        return ret;
    }
};

/*
[1]
0
[0,10]
2
[1,3,6]
3
[2,7,2]
1
[3,2,10]
2

*/