/*
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
*/
// dfs with memorization(dp) O(n^2) O(n^2)
class Solution {
private:
    vector<vector<int>>dp;// DP[i][j] means the max score between nums[i ... j].
    int score(vector<int> nums, int i, int j){
        if(i>j) return 0;
        if(dp[i][j] == -1){
            // max of two choices:
            // - p1 select i + min(p2 select i+1, p2 select j)
            // - p1 select j + min(p2 select i  , p2 select j-1)
            dp[i][j] = max(nums[i] + min(score(nums, i+2, j), score(nums, i+1, j-1)),
                           nums[j] + min(score(nums, i, j-2), score(nums, i+1, j-1)));
        }
        return dp[i][j];
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n,-1));
        int tot = 0;// Total scores.
        for(int i=0; i<n; ++i){
            dp[i][i] = nums[i];
            tot += nums[i];
        }
        score(nums, 0, n-1);
        // Compare player1 score and player2 score (the left nums sum)
        return dp[0][n-1]>=tot-dp[0][n-1]?true:false;
    }
};