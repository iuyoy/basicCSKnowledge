/*
In an array A containing only 0s and 1s, a K-bit flip consists of choosing a (contiguous) subarray of length K and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of K-bit flips required so that there is no 0 in the array.  If it is not possible, return -1.

 

Example 1:

Input: A = [0,1,0], K = 1
Output: 2
Explanation: Flip A[0], then flip A[2].
Example 2:

Input: A = [1,1,0], K = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we can't make the array become [1,1,1].
Example 3:

Input: A = [0,0,0,1,0,1,1,0], K = 3
Output: 3
Explanation:
Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]
 

Note:

1 <= A.length <= 30000
1 <= K <= A.length
*/

// Flip each first left zero
// O(kn) n is the number of zero
class Solution {
public:
    void flips(vector<int>&A, int start, int K){
        for(int i=0; i<K; ++i)
            A[start+i] = !A[start+i];
    }
    int minKBitFlips(vector<int>& A, int K) {
        int ret = 0;
        int i = 0;
        for(; i<=A.size()-K; ++i){
            if(A[i] == 0){
                flips(A, i, K);
                ++ret;
            }
        }
        for(;i<A.size(); ++i)
            if(A[i] == 0) return -1;
        return ret;
    }
};

// with queue not filp by simulate O(n) n is the number of zero
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int ret = 0;
        int i = 0;
        int signal = 0;
        queue<int> stop;
        for(; i<A.size(); ++i){
            if(A[i] ^ signal == 0){
                if(i+K>A.size()) return -1;
                stop.push(i+K-1);
                signal = !signal;
                ++ret;
            }
            if(i == stop.front()){
                signal = !signal;
                stop.pop();
            }
        }
        return ret;
    }
};