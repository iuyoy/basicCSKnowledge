/*
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n], m;
        int i , j;
        while(l<=r){
            m = (l+r)/2;// not overflow
            int sm = 0, lg = 0;
            for(i = n, j = i-1; i>0; --i){
                int diff = nums[i] - m;
                // cout<<diff<<endl;
                while(j>=0 && nums[j]>diff)
                    --j;
                sm += i-j-1;
                while(j>=0 && nums[j]==diff)
                    --j;
                lg += i-j-1;
            }
            if(k<=sm)
                r = m - 1;
            else if(k>lg)
                l = m + 1;
            else
                return m;
        }
        return l;
    }
};
