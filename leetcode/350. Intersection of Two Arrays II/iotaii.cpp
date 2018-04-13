/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
 two points
What if nums1's size is small compared to nums2's size? Which algorithm is better?
 hash?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 both big sorted two points
*/
// hash Time: O(m + n) Space: O(m)
// two point O(max(m, n)*log(max(m, n))) Space: O(m + n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>hash1, hash2;
        for(int n:nums1){
            ++hash1[n];
        }
        vector<int> ret;
        for(int n:nums2){
            if(hash1[n] > 0){
                ret.push_back(n);
                --hash1[n];
            }
        }
        return ret;
    }
};
