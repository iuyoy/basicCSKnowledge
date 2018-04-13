/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Sort both side of the interval, and then pick the max non-overlapping ones.

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
            ++left;
        while (arr[right] >= mid && left < right)
            --right;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        ++left;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval* ret = (struct Interval*)malloc(sizeof(struct Interval) * intervalsSize);
    int *left = (int *) malloc(sizeof(int) * intervalsSize);
    int *right = (int *) malloc(sizeof(int) * intervalsSize);
    int i = 0;
    while(i<intervalsSize){
        left[i] = intervals[i].start;
        right[i] = intervals[i].end;
        ++i;
    }
    quick_sort(left, intervalsSize);
    quick_sort(right, intervalsSize);
    *returnSize = 0;// Index of ret.
    for(i=0;i<intervalsSize;++i){
        ret[*returnSize].start = left[i];
        while(i<intervalsSize-1&&left[i]<=left[i+1]&&left[i+1]<=right[i])
            ++i;
        ret[*returnSize].end = right[i];
        ++(*returnSize);
    }
    //Free
    return ret;
}
