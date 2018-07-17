/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
 // O(n)
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    int i = 0;
    struct Interval* ret = (struct Interval*)malloc(sizeof(struct Interval) * (intervalsSize+1));
    (*returnSize) = 0;
    for(;i<intervalsSize && intervals[i].end < newInterval.start;++i,++(*returnSize)){
        ret[(*returnSize)].start = intervals[i].start;
        ret[(*returnSize)].end = intervals[i].end;
    }
    if(i<intervalsSize)
        ret[(*returnSize)].start = min(newInterval.start, intervals[i].start);
    else
        ret[(*returnSize)].start = newInterval.start;
    while(i<intervalsSize && newInterval.end >= intervals[i].start)++i;
    if(i>0)
        ret[(*returnSize)].end = max(newInterval.end, intervals[i-1].end);
    else
        ret[(*returnSize)].end = newInterval.end;
    ++(*returnSize);
    for(;i<intervalsSize;++i,++(*returnSize)){
        ret[(*returnSize)].start = intervals[i].start;
        ret[(*returnSize)].end = intervals[i].end;
    }
    // while(i<intervalsSize){
    //     ret[(*returnSize)].start = intervals[i].start;
    //     ret[(*returnSize)].end = interval[i].end;
    //     ++i;
    //     ++(*returnSize);
    // }
    return ret;

}
