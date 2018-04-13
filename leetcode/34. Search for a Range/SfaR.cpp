/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
// Binary Search O(logn)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int dis = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target));
        if(dis==0 || nums[dis-1] != target)
            return ret;
        ret[1] = dis-1;
        ret[0] = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        return ret;
    }
};
