/*
In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.
*/

// for S=0, count 0 and calculate; 
// for s>0, mark the loc of 1, result is (pre+zeros+1) * (pos-zeros+1) for every S number of 1;
// O(n) O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ret = 0;
        if(S == 0){
            int con = 0;
            for(auto a:A)
                if(a == 0)
                    ++con;
                else{
                    ret += (con+1)*con/2;
                    con = 0;
                }
            ret += (con+1)*con/2;
        }else{
            vector<int> loc1 = {-1};
            for(int i=0;i<A.size(); ++i)
                if(A[i]) loc1.push_back(i);
            loc1.push_back(A.size());
            for(int i=1; i<loc1.size()-S; ++i)
                ret += (loc1[i] - loc1[i-1])*(loc1[i+S]-loc1[i+S-1]);
        }
        return ret;
    }
};
// Faster solution exists