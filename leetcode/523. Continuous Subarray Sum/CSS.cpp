/*
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/
// DP O(n^2) O(n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        if(k==0){
            for(int i = 0; i<n-1; ++i)
                if(nums[i] == 0 && nums[i+1] == 0) return true;
            return false;
        }
        vector<int> dp(n);
        for(int i=0; i<n; ++i){
            dp[i] = nums[i]%k;
            for(int j=0; j<i; ++j){
                dp[j] =(dp[j]+dp[i])%k;
                if(dp[j] == 0) return true;
            } 
        }
        return false;
    }
};
/*
[23,2,4,6,7]
6
[23,2,6,4,7]
0
[0,0]
0
[0,1,0]
0
*/