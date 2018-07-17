/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*/

int arrayPairSum(int* nums, int numsSize) {
    int i = 0;
    int hash[20001]={0};
    for(;i<numsSize;i++)
        hash[nums[i]+10000] ++;
    bool flag = true;
    int max_sum = 0;
    for(i=0;i<20001;i++)
        for(;hash[i]!=0;hash[i]--)
        {
            if(flag) max_sum += i-10000;
            flag = !flag;
        }
    return max_sum;
}
