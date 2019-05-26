/*
Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

 

Example 1:

Input: [3,6,9,12]
Output: 4
Explanation: 
The whole array is an arithmetic sequence with steps of length = 3.
Example 2:

Input: [9,4,7,2,10]
Output: 3
Explanation: 
The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: [20,1,15,3,10,5,8]
Output: 4
Explanation: 
The longest arithmetic subsequence is [20,15,10,5].
 

Note:

2 <= A.length <= 2000
0 <= A[i] <= 10000
*/

// brute with umap O(n^2)
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        // umap store values and its idx in order.
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i<A.size(); ++i)
            if(umap.find(A[i]) == umap.end())
                umap[A[i]] = vector<int>({i});
            else
                umap[A[i]].push_back(i);
        int ret = 2;
        // diff = 0 
        for(auto ele:umap){
            int count = ele.second.size();
            ret = max(ret, count);
        }
        // diff != 0, brute cal
        for(int i=0; i<A.size() - 1; ++i)
            for(int j=i+1; j<A.size(); ++j){
                int count = 2, gap = A[j] - A[i], curidx = j, next = A[j]+gap;
                if(gap != 0){
                    while(umap.find(next) != umap.end()){
                        auto it = upper_bound(umap[next].begin(), umap[next].end(), curidx);
                        if(it != umap[next].end() && (*it)>curidx){
                            ++count;
                            curidx = (*it);
                            next += gap;
                        }else
                            break;
                    }
                    ret = max(ret, count);
                }
            }
        return ret;     
    }
};