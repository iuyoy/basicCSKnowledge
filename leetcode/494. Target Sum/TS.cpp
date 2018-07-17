/*

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
// Brute O(2^n) TLE
class Solution {
private:
    int ret;
    int n;
    void brute(vector<int> nums, int i, int S){
        if(i < n-1){
            brute(nums, i+1, S-nums[i]);
            brute(nums, i+1, S+nums[i]);
        }else {
            if(nums[i] == S)
                ++ret;
            if(nums[i] == -S) // Pay attation ZERO
                ++ret;
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        ret = 0;
        n = nums.size();
        brute(nums, 0, S);
        return ret;
    }
};

// DP O(l*n) l is the max count of sums. O(l)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ret = 0;
        int n = nums.size();
        if(n == 0) return 0;
        unordered_map<int, int> sums1;// = new unordered_map<int, int>({0, 1});
        unordered_map<int, int> sums2;// = new unordered_map<int, int>();
        sums1[0] = 1;
        for(auto num:nums){
            for(auto it:sums1){
                int sums = it.first, cot = it.second;
                sums2[sums+num += cot;
                sums2[sums-num += cot;
            }
            sums1.clear();
            swap(sums1, sums2);
        }
        return sums1[S];
    }
};
/*
[1,0]
1
[47,23,38,38,3,37,18,29,27,39,29,25,4,2,0,47,10,39,23,17]
15
*/