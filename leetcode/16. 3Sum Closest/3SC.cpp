/*

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

// two pointers O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        for(int first = 0; first<n; ++first){
            int l = first+1, r = n-1;
            int t = target - nums[first];
            while(l<r){
                if(abs(nums[l]+nums[r]-t) < abs(ret - target))
                    ret = nums[l] + nums[r] + nums[first];
                if(nums[l] + nums[r] == t)
                    return target;
                else if(nums[l] + nums[r] > t){
                    --r;
                }else{
                    ++l;
                }
            }
            if(nums[first] >= target)
                break;
        }
        return ret;
    }
};