/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

//DP O(m*n) m=nums.size(), n = target
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        for(int num:nums)
            if(num<=target)
                dp[num] = 1;
            
        for(int i=1; i<=target; ++i)
            for(int num:nums)
                if(i-num>0)
                    dp[i] += dp[i-num];
        return dp[target];
    }
};
//Follow up , -1 1 endless, add the max times of each number