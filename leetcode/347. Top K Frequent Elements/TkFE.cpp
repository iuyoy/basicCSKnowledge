/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
//Similar as 451
#define umii unordered_map<int, int>

// Bucket+hash O(n) or Heap Sort+hash O(nlogK)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = nums.size();
        umii cots;
        for(int num:nums) ++cots[num];
        vector<vector<int>> bucket(n+1, vector<int>());
        for(auto cot:cots)
            bucket[cot.second].push_back(cot.first);
        vector<int> ret;
        for(int i=n; i>=0&&k>0; --i)
            if(!bucket[i].empty()){
                ret.insert(ret.end(), bucket[i].begin(), bucket[i].end());
                k-=bucket[i].size();
            }
        return ret;
    }
};
