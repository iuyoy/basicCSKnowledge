#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
*/

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

//TC O(n) SC O(n)
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    int *hash = (int *) malloc(sizeof(int) * (numsSize - 1));
    int i = 0,hash_i = 1;
    int max1_i = 0, max2_i[2] = {0};
    int * max3_i = (int *) malloc(sizeof(int) * 3);
    max2_i[1] = k;
    max3_i[0] = 0;max3_i[1] = k;max3_i[2] = k+k;
    memset(hash, 0, sizeof(int) * (numsSize - 1));
    // Calculate the sum of each K continue numbers.
    for(;i<k;i++)
        hash[0] += nums[i];
    for(;i<numsSize;i++,hash_i++)
        hash[hash_i] = hash[hash_i - 1] - nums[i-k] + nums[i];

    for(i=2*k+1;i<numsSize-1;i++){
        if(hash[i-k-k] > hash[max1_i])
            max1_i = i-k-k;
        if(hash[max1_i] + hash[i-k] > hash[max2_i[0]] + hash[max2_i[1]]){
            max2_i[0] = max1_i;
            max2_i[1] = i-k;
        }
        if(hash[max2_i[0]] + hash[max2_i[1]] + hash[i] > hash[max3_i[0]]+hash[max3_i[1]]+hash[max3_i[2]]){
            max3_i[0] = max2_i[0];
            max3_i[1] = max2_i[1];
            max3_i[2] = i;
        }
         // printf("max3:%d %d %d\n",max3_i[0],max3_i[1],max3_i[2]);
    }
    *returnSize = 3;
    return max3_i;

}

//TC O(n) SC O(n) a liite advanced
#define min(a,b) (a)>(b)?(b):(a)
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    int *hash = (int *) malloc(sizeof(int) * (numsSize - 1));
    int i = 0,hash_i = 1;
    int max1_i = 0, max2_i[2] = {0};
    int * max3_i = (int *) malloc(sizeof(int) * 3);
    max2_i[1] = k;
    max3_i[0] = 0; max3_i[1] = k; max3_i[2] = k+k;
    memset(hash, 0, sizeof(int) * (numsSize - 1));
    // Calculate the sum of each K continue numbers.
    for(;i<k;i++)
        hash[0] += nums[i];
    for(;i<numsSize;i++,hash_i++)
        hash[hash_i] = hash[hash_i - 1] - nums[i-k] + nums[i];
    for(i=2*k + 1;i<numsSize-1;i++){
        if(hash[i-k-k] > hash[max1_i])
            max1_i = i-k-k;
        if(hash[i-k] > min(hash[max2_i[0]],hash[max2_i[1]]) && hash[max1_i] + hash[i-k] > hash[max2_i[0]] + hash[max2_i[1]]){
            max2_i[0] = max1_i;
            max2_i[1] = i-k;
        }
        if(hash[i] > min(hash[max3_i[0]], min(hash[max3_i[1]], hash[max3_i[2]])) && hash[max2_i[0]] + hash[max2_i[1]] + hash[i] > hash[max3_i[0]]+hash[max3_i[1]]+hash[max3_i[2]]){
            max3_i[0] = max2_i[0];
            max3_i[1] = max2_i[1];
            max3_i[2] = i;
        }
      // printf("max3:%d %d %d\n",max3_i[0],max3_i[1],max3_i[2]);
    }
    *returnSize = 3;
    return max3_i;

}
