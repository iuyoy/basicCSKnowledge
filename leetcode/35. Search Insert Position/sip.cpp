/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 1:

Input: [1,3,5,6], 0
Output: 0
*/
// binary search O(log(n))
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int n = nums.size();
        if(n == 0 || target <= nums[0]) return 0;
        if(target > nums[n-1]) return n;
        int l = 0, r = n-1, mid = 0;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid]<target)
                l = mid+1;
            else//nums[mid]>target
                r = mid-1;
        }
        return l;
    }
};
