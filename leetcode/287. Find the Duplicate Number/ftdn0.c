/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

// TS O(n^2) CS O(1) input read-only
// nested loop
int findDuplicate(int* nums, int numsSize) {
    int i, j, flag;
    for(i=0;i<numsSize;i++){
        for(flag = 0,j = 0;j<numsSize;j++){
            if(nums[j] == i)
                if(flag)
                    return i;
                else
                    flag = 1;
        }
    }
    return -1;// wipe warning.
}

// TS O(n) CS O(n) input read-only
// hash
int findDuplicate(int* nums, int numsSize) {
    int *hash = (int *) malloc(sizeof(int) * numsSize);
    int i=0;
    memset(hash, 0, numsSize*sizeof(int));
    for(;i < numsSize; i++)
        if(hash[nums[i]])
            return nums[i];
        else
            hash[nums[i]] = 1;
    return -1;
}

// TS O(1) CS O(n) input write
// Trick：mark with minus
// It is not a good solution in production environment, cause original array is changed, and sometions it is unmodifiable.
int findDuplicate(int* nums, int numsSize) {
    int i=0, key;
    for(; i < numsSize; i++){
        key = abs(nums[i]);
        if(nums[key]<0)
            return key;
        else
            nums[key] = -nums[key];
    }
    return -1;
}
