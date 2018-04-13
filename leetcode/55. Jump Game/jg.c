/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

// Method1
bool canJump(int* nums, int numsSize) {
    int i = 1;
    int j;
    int max = nums[0];
    if(numsSize == 1)
        return true;
    while(i<numsSize&&max>=i){
        j = i + nums[i];
        if(j>max){
            if(j>numsSize-1)
                return true;
            max = j;
        }
        ++i;
    }
    if(max>numsSize-1)
        return true;
    return false;
}

// method2
bool canJump(int* nums, int numsSize) {
    int *hash = (int*)malloc(sizeof(int)*numsSize);
    memset(hash,0,sizeof(int)*numsSize);
    int i = 0;
    int j;
    nums[numsSize-1]=0;
    hash[0] = 1;
    while(i<numsSize){
        if(hash[i]){
            if(i+nums[i]>=numsSize-1)
                return true;
            for(j=1;j<=nums[i];++j)
                hash[i+j]=1;
        }
        ++i;
    }
    return false;
}
