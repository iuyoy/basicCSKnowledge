/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/
//DP n(n^3)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        dp[0][0] = 1;
        dp[n+1][n+1] = 1;
        // cout<<nums[0]<<" "<<nums[n+1]<<endl;
        for(int length = 0; length <n; ++length){
            for(int i = 1; i<=n-length; ++i){
                int end = i + length;
                int j = i;
                for(; j<=end; ++j){
                    // cout<<nums[i-1]*nums[j]*nums[end+1]<<endl;
                    dp[i][end] = max(dp[i][end], dp[i][j-1] + dp[j+1][end] + nums[i-1]*nums[j]*nums[end+1]);
                }
                // cout<<"dp["<<i<<"]["<<end<<"]:"<<dp[i][end];
            }
            // cout<<endl;
        }
        return dp[1][n];
    }
};
