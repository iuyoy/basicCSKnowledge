/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

*/
// Binary Search O(k+log(n-k)) ~ O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int n = nums.size()-1;
        int l = 0, r = n, mid;
        while(l<=r){
            while(l<r && nums[l]==nums[l+1])++l;
            while(l<r && nums[r]==nums[r-1])--r;

            mid = l+(r-l)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid]>target)
                if(target<=nums[n] && nums[mid]>nums[n])
                    l = mid+1;
                else
                    r = mid-1;
            else// nums[mid]<target
                if(target>nums[n] && nums[mid]<=nums[n])
                    r = mid-1;
                else
                    l = mid+1;
        }
        return false;
    }
};
