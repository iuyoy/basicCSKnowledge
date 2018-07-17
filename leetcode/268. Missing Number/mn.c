/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

// SC O(n) TC O(n)
// Hash
int missingNumber(int* nums, int numsSize) {
    int* hash = (int *) malloc(sizeof(int) * (numsSize + 1));
    int i = 0;
    memset(hash, 0, numsSize+1);
    while(i<numsSize)
        hash[nums[i++]] = 1;
    i = 0;
    while(i < numsSize + 1)
        if(hash[i++] == 0)
            break;
    return i-1;
}

// SC O(k) TC O(n)
int missingNumber(int* nums, int numsSize) {
    /// printf("\n");
    int i = 0, flag = 0, zero_index = -1;
    int abs_index, abs_value;
    while(i<numsSize){
        abs_index = abs(nums[i]);
        if(abs_index == numsSize){
            flag = 1;
        }else {
            abs_value = nums[abs_index];
            if(abs_value == 0){//Miss1: 0 has no negative number.
                if(nums[0] > 0)
                    nums[0] = - nums[0];
                nums[abs_index] = -1;
            }
            else
                nums[abs_index] = -abs_value;
        }
        // printf("%d %d %d\n",i,nums[i],nums[abs(nums[i])]);
        i++;
    }
    i = 0;
    while(i<numsSize){
        // printf("%d %d\n",i,nums[i]);
        if(nums[i] > 0)
            return i;
        i++;
    }
    if(flag){
        return 0;
    }
    return numsSize;
}
