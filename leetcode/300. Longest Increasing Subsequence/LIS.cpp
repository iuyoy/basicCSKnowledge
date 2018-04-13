/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

// DP O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 1);
        int ret = 0;
        for(int i = 0;i<n; ++i){
            for(int j = 0; j<i; ++j){
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

// Binary Search O(nLogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp;
        for(int i = 0;i<n; ++i){
            int where = distance(dp.begin(), lower_bound(dp.begin(), dp.end(), nums[i]));
            if(where == dp.size())
                dp.push_back(nums[i]);
            else
                dp[where] = nums[i];
        }
        return dp.size();
    }
};
