/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

//O(n)
int minSubArrayLen(int s, int* nums, int numsSize) {
    int left= 0,right=0;
    int sum = 0;
    int min = numsSize;
    int temp = 0;
    int flag;
    while(right<numsSize){
        sum += nums[right++];
        temp ++;
        flag = 0;
        while(sum>=s){
            sum -= nums[left++];
            temp --;
            flag = 1;
        }
        if(flag && temp<min){
            min = temp;
            flag = 1;
        }

    }
    if(min==numsSize)
        return 0;
    return min+1;
}
