/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
//Binary Search O(log(n))
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        const int n = r-1;
        while(l<r){
            mid = l+(r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid]>target)
                if(target<=nums[n] && nums[mid]>nums[n])
                    l = mid+1;
                else
                    r = mid;
            else// nums[mid]<target
                if(target>nums[n] && nums[mid]<=nums[n])
                    r = mid;
                else
                    l = mid+1;
        }
        return -1;
    }
};
// Hard Code of the above Codes
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        const int n = r-1;
        if(target<=nums[n])
            while(l<r){
                mid = (l+r)/2;
                if(nums[mid] == target)
                    return mid;
                if(nums[mid]>target)
                    if(nums[mid]>nums[n])
                        l = mid+1;
                    else
                        r = mid;
                else
                    l = mid+1;
            }
        else
            while(l<r){
                mid = (l+r)/2;
                if(nums[mid] == target)
                    return mid;
                if(nums[mid]>target)
                    r = mid;
                else
                    if(nums[mid]<=nums[n])
                        r = mid;
                    else
                        l = mid+1;
            }
        return -1;
    }
};
