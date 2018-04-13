/*
A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
Note:

A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length - 1) / 2.
*/
// https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378
// Binary Search(Nlog(N))
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int n = A.size()-1;
        double l = 0.0, r = 1.0, m;
        int p = 0, q = 1, i , j;
        while(l<r){
            m = (l+r)/2;
            int cot = 0;

            for(i = 1, j = 0, p = 0, q = 1; i<=n; ++i){
                double dec = m*A[i];
                while(A[j]<dec)// Calculate the num of A[j]/A[i] < m
                    ++j;
                cot += j;

                if (j>0 && p * A[i] < q * A[j-1]) {
                    p = A[j-1];
                    q = A[i];
                }
            }
            if(cot == K)
                break;
            else if(cot > K)
                r = m;
            else
                l = m;
        }
        return {p, q};
    }
};

// Priority Queue O(k * logn)
#define pdii pair<double,pair<int,int>>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        // auto comp = [A]( pair<double, int, int> a, pair<double, int, int> b ) { return A[a.first]/A[a.second]>=A[b.first]/A[b.second]; };
        priority_queue< pdii, vector<pdii>, greater<pdii>> pq;
        const int n = A.size();
        for(int i = 1; i<n; ++i)
            pq.push({(double)1/A[i], {0, i}});
        while(--K>0){
            auto top = pq.top();
            pq.pop();
            ++top.second.first;
            if(top.second.first<top.second.second);
                pq.push({(double)A[top.second.first]/A[top.second.second], {top.second.first, top.second.second}});
        }
        return {A[pq.top().second.first], A[pq.top().second.second]};
    }
};
