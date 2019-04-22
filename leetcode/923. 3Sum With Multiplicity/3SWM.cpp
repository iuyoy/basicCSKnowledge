/*
Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

As the answer can be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (A[i], A[j], A[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: A = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
 

Note:

3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300
*/
// Three Pointers.
class Solution {
public:
    int threeSumMulti(vector<int>& nums, int t) {
        long m = 1e9+7;
        const int n = nums.size();
        long ret = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; ++i){
            if(nums[i]>t) break;
            int j=i+1, k = n-1;
            int ta = t-nums[i];
            while(j<k){
                if(nums[j] + nums[k] == ta){
                    if(nums[k] == nums[j]) {
                        ret = (ret+(k-j+1)*(k-j)/2)%m;
                        break;
                    }
                    else{
                        int left = 1, right = 1;
                        while(j<k && nums[j+1] == nums[j]){
                            ++j;
                            ++left;
                        }
                        while(k>j && nums[k-1] == nums[k]){
                            --k;
                            ++right;
                        }
                        ret = (ret + left*right)%m;
                        ++j;
                        --k;
                    }
                }else if(nums[j] + nums[k] > ta)
                    --k;
                else 
                    ++j;
            }
        }
        return ret;
    }
};