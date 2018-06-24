/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/
// Stack O(n), O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), -1);
        stack<int> smalls;// store index
        for(int i=0;i<nums.size();++i){
            while(smalls.size() && nums[smalls.top()]<nums[i]){
                ret[smalls.top()] = nums[i];
                smalls.pop();
            }
            smalls.push(i);    
        }
        for(int i=0;i<nums.size()&&smalls.size();++i){
            while(nums[smalls.top()]<nums[i]){
                ret[smalls.top()] = nums[i];
                smalls.pop();
            }
        }
        return ret;
    }
};