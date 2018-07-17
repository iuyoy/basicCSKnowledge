/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/
class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        const int n = nums.size();
        int mid = 0;
        // find the not decrease progressively index,
        // A number before mid must be swapped with a number after mid.
        for(;mid<n-1&&nums[mid]>=nums[mid+1];++mid);
        if(mid<n-1){
            int max_i = ++mid;
            for(++mid; mid<n; ++mid)
                if(nums[mid]>=nums[max_i])
                    max_i = mid;
            int i = 0;
            for(;nums[i] >= nums[max_i];++i);
            swap(nums[max_i], nums[i]);
        }
        return stoi(nums);
    }
};
