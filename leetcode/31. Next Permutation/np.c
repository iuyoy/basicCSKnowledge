/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
1. Find the first element that there is an element larger than it in the right, from right of the array to left.
2. Sort the elements behind that element;
3. swap the element wiht the min element that larger than it in its right.
*/
// There is a built-in sort function
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}
void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    while(nums[i]>=nums[i+1]&&i>=0)
        --i;
    // printf("i:%d %p\n",i,(&nums[i+1])[0]);
    quick_sort(&nums[i+1], numsSize-i-1);
    if(i == -1)
        return;
    int j = i+1;
    for(;nums[j]<=nums[i];++j);
    swap(&nums[i],&nums[j]);
}
