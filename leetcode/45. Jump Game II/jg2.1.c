/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

//striaght, not good
int jump(int* nums, int numsSize) {
    int i = 0;
    for(;i<numsSize;++i)
        nums[i] = i+nums[i];
    int flag = numsSize-1;
    int count = 0;
    for(i=0;flag!=0;++i){
        // printf("nums[%d]:%d = flag:%d\n",i,nums[i], flag);
        if(nums[i]>=flag){
            flag = i;
            ++count;
            i = -1;
        }
    }
    return count;
}

//DP, not good ag
int jump(int* nums, int numsSize) {
    int i = 0, j;
    int *steps = (int *)malloc(sizeof(int)*numsSize);
    memset(steps, 0, sizeof(int)*numsSize);
    steps[0] = 0;
    for(;i<numsSize-1;++i){
        if(i+nums[i]>=numsSize-1)
            return steps[i]+1;
        for(j=1;j<=nums[i];++j){
            if(steps[i+j]==0)
                steps[i+j] = steps[i]+1;
        }

    }
    return steps[numsSize-1];
}

//BFS
int jump(int* nums, int numsSize) {
    int i, j;
    int start = 0;
    int end = 0;
    int max=nums[0];
    int count=0;
    if(numsSize==1)
        return 0;
    while(1){
        ++count;
        for(i=start;i<=end;++i){
            if(i+nums[i]>max)
                max = i+nums[i];
        }
        if(max>=numsSize-1) break;
        start=end+1;
        end=max;
    }
    return count;
}
