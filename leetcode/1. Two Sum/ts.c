/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //TS O(n^2)
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0, j;
    int sum = 0;
    int* ret = (int*)malloc(sizeof(int)*2);
    for(;i<numsSize;++i){
        sum = target - nums[i];
        for(j=i+1;j<numsSize;++j){
            if(nums[j] == sum){
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}

//TS O(n) with hash;
int* twoSum(int* nums, int numsSize, int target) {
   int hash[200001] = {2};
   int i = 0;
   int *ret = (int *)malloc(sizeof(int)*2);
   for(;i<numsSize;++i){
       hash[nums[i]+100000] = i+1;
   }
   for(i=0;i<numsSize;++i){
       int another = hash[target-nums[i]+100000];
       if(another>0 && another - 1 != i){
           ret[0] = i;
           ret[1] = another-1;
           break;
       }
   }
   return ret;
}
