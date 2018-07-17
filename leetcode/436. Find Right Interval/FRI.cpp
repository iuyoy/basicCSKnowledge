/*
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:
You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
Example 1:
Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.
Example 2:
Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
Example 3:
Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 // Sort + Gredey O(nlogn)
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        const int n = intervals.size();
        vector<int> ret(n);
        // initialize original index locations
        vector<size_t> start(n);
        iota(start.begin(), start.end(), 0);
        vector<size_t> end(n);
        iota(end.begin(), end.end(), 0);
        // sort indexes based on comparing values in v
        sort(start.begin(), start.end(), [&intervals](size_t i1, size_t i2) {return intervals[i1].start < intervals[i2].start;});
        sort(end.begin(), end.end(), [&intervals](size_t i1, size_t i2) {return intervals[i1].end < intervals[i2].end;});
        int i = 0;
        for(size_t ei:end){
            int end = intervals[ei].end;
            while(i<n){
                // cout<<end<<" "<<intervals[start[i]].start<<endl;
                if(intervals[start[i]].start>=end && ei!=start[i])
                    break;
                ++i;
            }
            if(i==n)
                ret[ei] = -1;
            else
                ret[ei] = start[i];
        }
        // for (auto i: start) {
        //     cout << intervals[i].start << endl;
        // }
        // for (auto i: end) {
        //     cout << intervals[i].end << endl;
        // }
        return ret;
    }
};
