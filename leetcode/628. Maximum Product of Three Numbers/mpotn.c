/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/
#define max(a,b) (a)>(b)?(a):(b)
int maximumProduct(int* nums, int numsSize) {
    if(numsSize < 3)
        return 0;
    int i=0;
    int temp = 0;
    int min1 = 1001, min2 = 1001, max1 = -1001, max2 = -1001, max3 = -1001;
    while(i<numsSize){
        temp = nums[i++];
        if(temp > max3){
            max1 = max2;
            max2 = max3;
            max3 = temp;
        }
        else if(temp > max2){
            max1 = max2;
            max2 = temp;
        }
        else if(temp > max1)
            max1 = temp;
        if(temp < min1){
            min2 = min1;
            min1 = temp;
        }
        else if(temp < min2)
            min2 = temp;
        // printf("%d %d %d %d %d\n", min1,min2,max1,max2,max3);
    }
    return max(min2*min1*max3, max1*max2*max3);
}
