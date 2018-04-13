/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1.
Note: Length of the array will not exceed 10,000.
*/
//SC O(3) TC O(n)
int findLengthOfLCIS(int* nums, int numsSize) {
    // n = 0,
    int i = 0;
    int count = 1;
    int max = 0;
    while(i<numsSize - 1)
        if(nums[i+1]>nums[i++])
            count ++;
        else{
            if(count>max)
                max = count;
            count = 1;
        }
    if(count>0&&numsSize>0)
        return max>count?max:count;
    return max;
}
