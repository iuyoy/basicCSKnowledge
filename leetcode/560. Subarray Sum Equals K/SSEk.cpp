/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

// prefix sum and hash, O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sums;
        int ps = 0, ret = 0;
        prefix_sums[0] = 1;
        for(auto num:nums){
            ps += num;
            ret += prefix_sums[ps-k];
            prefix_sums[ps] ++;
        }
        return ret;
    }
};