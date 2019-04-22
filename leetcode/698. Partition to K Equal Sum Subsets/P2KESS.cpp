/*

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/

typedef vector<int> vi;

// pruning dfs 
class Solution {
private:
    int t;
    bool dfs(vi& nums, int target, vi& visited, int k, int start){
        if(k==1) return true;
        // cout<<target<<" "<<cur<<endl;
        if(target == 0) 
            return dfs(nums, t, visited, k-1, 0);
        for(int i=start; i<nums.size(); ++i){
            if(!visited[i]){
                visited[i] = 1;
                if( dfs(nums, target-nums[i], visited, k, i+1) )
                    return true;
                visited[i] = 0;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        t = sum/k;
        if(sum%k != 0 || nums.back()>t) return false;
        
        vi visited(nums.size(), 0);
        return dfs(nums, t, visited, k, 0);
    }
};

// memorialized dfs with bit manipulation
class Solution {
private:
    int t;
    bool dfs(vi& nums, vi& dp, int used, int target){
        // cout<<used<<" "<<dp[used]<<endl;
        if(dp[used] == -1){
            dp[used] = 0;
            for(int i=0; i<nums.size() && nums[i]<=target; ++i){
                if(((used>>i)&1) == 0){//ith not used
                    if(dfs(nums, dp, used | (1<<i), nums[i]==target? t:target-nums[i])){
                        dp[used] = 1;
                        break;
                    }
                }
            }
        }
        return dp[used]; 
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        t = sum/k;
        if(sum%k != 0 || nums.back()>t) return false;
        vi dp(1<<n, -1);
        dp[(1<<n)-1] = 1;// mark the used nums.
        bool ret = dfs(nums, dp, 0, t);
        // for(int i=0;i<(1<<n); ++i){
        //     cout<<i<<" "<<dp[i]<<endl;
        // }
        return ret;
    }
};
/*
[4,3,2,3,5,2,1]
4
[1,2,3,4]
2
[1,2,3,6]
3
[815,625,3889,4471,60,494,944,1118,4623,497,771,679,1240,202,601,883]
3
[4,5,3,2,5,5,5,1,5,5,5,5,3,5,5,2]
13
[2,2,2,2,3,4,5]
4
*/