/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
// Algorithm 1: Brute Force O(n^2)
// Algorithm 2: Divide and Conquer O(n)
// Kadane's algorithm (Algorithm 3: Dynamic Programming) O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        if(n==0)
            return INT_MIN;
        int i = 1, current = nums[0];
        int ret = current;
        for(;i<n;++i){
            if(current<0)
                current = 0;
            current+=nums[i];
            ret = max(ret, current);
        }
        return ret;
    }
};
