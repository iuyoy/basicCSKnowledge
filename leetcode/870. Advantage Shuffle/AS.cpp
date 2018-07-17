/*
User Accepted: 0
User Tried: 0
Total Accepted: 0
Total Submissions: 0
Difficulty: Medium
Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

 

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]
Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]
 

Note:

1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9

*/
// Greedy + Sort O(nlogn) O(n)
class Solution{
  public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B){
        int n = A.size();
        vector<int> C(n);
        vector<int> ret(n);
        for (int i = 0; i < n; ++i)
            C[i] = i;
        sort(A.begin(), A.end());
        sort(C.begin(), C.end(), [B](int a, int b) { return B[a] < B[b]; });
        // for(int i=0; i<n; ++i)
        //     cout<<C[i]<<" "<<B[C[i]]<<" "<<A[i]<<endl;
        int r = n - 1, i = n - 1;
        int l = 0;
        while (r >= l){
            if (A[r] > B[C[i]])
                ret[C[i]] = A[r--];
            else
                ret[C[i]] = A[l++];
            --i;
        }
        return ret;
    }
};
