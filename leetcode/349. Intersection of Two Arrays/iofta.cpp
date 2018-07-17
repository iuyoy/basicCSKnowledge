/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

//O(n+m) O(n+m)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        unordered_set<int> unique;
        vector<int> ret;
        for(int num:nums1)
            if(hash.find(num) == hash.end())
                hash.insert(num);
        for(int num:nums2)
            if(hash.find(num) != hash.end())
                if(unique.find(num) == unique.end()){
                    unique.insert(num);
                    ret.push_back(num);
                }
        return ret;
    }
};

//O(n+m)? O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(), nums1.end());
        vector<int> ret;
        for(int num:nums2)
            if(hash.find(num) != hash.end()){
                ret.push_back(num);
                hash.erase(num);
            }
        return ret;
    }
};
