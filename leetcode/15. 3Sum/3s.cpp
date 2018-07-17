/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
// Tow Point O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> rets;
        sort(nums.begin(), nums.end());
        for(int first = 0; first<n-2; ++first){
            if(nums[first]>0)
                break;
            while(first>0 && nums[first] == nums[first-1]){
                ++first;
            }
            int i = first + 1, j = n - 1;
            int target = -nums[first];
            while(i<j){
                if(nums[i] == nums[i-1] && nums[i] != nums[first]){
                    ++i;
                    continue;
                }
                if(j<n-1 && nums[j] == nums[j+1]){
                    --j;
                    continue;
                }
                int sum = nums[i] + nums[j];
                if(sum == target){
                    vector<int> ret({nums[first], nums[i], nums[j]});
                    rets.push_back(ret);
                    ++i;
                    --j;
                }
                else if(sum > target)
                    --j;
                else
                    ++i;
            }
        }
        return rets;
    }
};
