/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // Time O(n) Space O(2n)
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int *hash = (int *) malloc (sizeof(int) * numsSize);
    int i = 0;
    int *ret = (int *) malloc (sizeof(int) * numsSize);
    *returnSize = 0;
    for(;i<numsSize;i++)
        if(hash[nums[i]])
            ret[(*returnSize)++] = nums[i];
        else
            hash[nums[i]] = 1;
    return ret;
}

// TC O(n) SC O(n) Exist
