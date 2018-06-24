/*
Given an array of unique integers, each integer is strictly greater than 1.

We make a binary tree using these integers and each number may be used for any number of times.

Each non-leaf node's value should be equal to the product of the values of it's children.

How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.

Example 1:

Input: A = [2, 4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: A = [2, 4, 5, 10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].


Note:

1 <= A.length <= 1000.
2 <= A[i] <= 10 ^ 9.
*/

// DP O(n^2)
#define m 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<long> dp(A.size(), 1);
        unordered_map<int, int> where;
        for(int i=0; i<A.size(); ++i)
            where[A[i]] = i;
        long ret = 1;
        for(int i = 1; i<A.size(); ++i){
            for(int j = 0; j<i; ++j){
                int ano = A[i]/A[j];
                if(A[i]%A[j]==0 && where.find(ano) != where.end())
                    dp[i] = (dp[i] + (dp[j]*dp[where[ano]])%m )%m;
            }
            ret = (ret + dp[i])%m;
        }
        return ret;
    }
};

// others, the vector dp and the umap where can be combined in an umap;
