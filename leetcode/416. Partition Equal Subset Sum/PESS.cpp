/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // index means sum, true means existence.
        if(nums.size() == 0) return true;
        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s%2) return false;
        s = s/2;
        vector<bool> dp(s);
        dp[0] = true;
        for(auto n:nums){
            for(int i=s-1;i>=0;--i){
                if(dp[i]){
                    if(i+n == s) return true;
                    if(i+n<s) dp[i+n] = true;
                }
            }
        }
        return false;
    }
};
/*
[1,5,11,5]
[1, 2, 3, 5]
[]
[1,2,3,4,5,6,7,8,9,10,21,12,13,14,15,16,17,18,19,20]
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
[1,2,5]
*/