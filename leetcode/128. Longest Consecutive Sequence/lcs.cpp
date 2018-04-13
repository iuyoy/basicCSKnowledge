/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
// sorting tc:o(nlogn)
// hash tc:o(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> umap;
        int left, right;
        int ret = 0;
        for(auto i:nums)
            if(umap.find(i) == umap.end()){
                left = (umap.find(i-1) == umap.end())?0:umap[i-1];
                right = (umap.find(i+1) == umap.end())?0:umap[i+1];
                umap[i] = left + right +1;
                umap[i - left] = umap[i];
                umap[i + right] = umap[i];
                ret = max(ret, umap[i]);
            }
        return ret;
    }
};

// PS: integer overflow is not considered in.
// [2147483647,-2147483648]

// left = (i == MIN_INT || umap.find(i-1) == umap.end())?0:umap[i-1];
// right = (i == MAX_INT || umap.find(i+1) == umap.end())?0:umap[i+1];
