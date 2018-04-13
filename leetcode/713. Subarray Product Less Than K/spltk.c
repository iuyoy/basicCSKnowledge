/*
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

*/

// int kinds(int n){
//     return ((double)n/2)*(n+1);
// }
int kinds(int n){
    return ((double)n/2)*(n+1);
}
int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    // int bcv_1[32] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647};
    int i=0,j=1;
    int same = 0;
    int ret = 0;
    int product = nums[0];
    if(k==0)
        return 0;
    while(j<numsSize&&i<=j){
        product*= nums[j];
        if(product>=k){
            // printf("%d,%d,%d,%d\n",i,j,same,kinds(j-i) - kinds(same));
            ret += kinds(j-i) - kinds(same);
            same = j-i;
            while(product>=k&i<numsSize){
                product/=nums[i++];
                same--;
            }
            ret += kinds(j-i) - kinds(same);
            same = j-i;
        }
        ++j;
    }
    // printf("%d\n",kinds(j-i) - kinds(same));
    ret += kinds(j-i) - kinds(same);
    return ret;
}
