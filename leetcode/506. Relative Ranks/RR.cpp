/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        vector<string> ret(n);
        for(int i=0; i<n; ++i)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [nums](int a, int b){return nums[a] > nums[b];});
        for(int i=0; i<n; ++i){
            if(i>=3) ret[idx[i]] = to_string(i+1);
            else if(i == 0) ret[idx[i]] = "Gold Medal";
            else if(i == 1) ret[idx[i]] = "Silver Medal";
            else if(i == 2) ret[idx[i]] = "Bronze Medal";
        }
        return ret;
    }
};

// much faster
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> idx;
        vector<string> ret(n);
        for(int i=0; i<n; ++i)
            idx.emplace_back(nums[i], i); //合并成一个数组
        sort(idx.rbegin(), idx.rend()); // 从右往左 从小到大排
        for(int i=0; i<n; ++i){
            if(i>=3) ret[idx[i].second] = to_string(i+1);
            else if(i == 0) ret[idx[i].second] = "Gold Medal";
            else if(i == 1) ret[idx[i].second] = "Silver Medal";
            else if(i == 2) ret[idx[i].second] = "Bronze Medal";
        }
        return ret;
    }
};