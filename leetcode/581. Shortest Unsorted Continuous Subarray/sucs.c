/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

int findUnsortedSubarray(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while(left<right && nums[left]<=nums[left+1])
        ++left;
    while(right>left && nums[right]>=nums[right-1])
        --right;
    // printf("1:%d %d\n",left,right);
    if(right == left)
        return 0;
    int i = left;
    --left;
    ++right;
    int count = right;
    while(i<count){
        while(left>=0&&nums[i]<nums[left])
            --left;
        while(right<numsSize&&nums[i]>nums[right])
            ++right;
        ++i;
    }
    // printf("2:%d %d\n",left,right);

    return right-left-1;

}
