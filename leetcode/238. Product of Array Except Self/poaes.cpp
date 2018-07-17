/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
//SC O(1) TC((n+1)*n/2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ret(n, 1);
        int i = 0, j;
        int product = 1;
        for(;i<n;++i){
            ret[i] = product;
            product *= nums[i];
            for(j=0;j<i;++j)
                ret[j] *= nums[i];
        }
        return ret;
    }
};

//SC O(n) TC(3n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> asc(n);
        vector<int> res(n);
        asc[0] = 1;
        res[n-1] = 1;
        int i = 1;
        for(;i<n;++i){
            asc[i] = asc[i-1] * nums[i-1];
            res[n-i-1] = res[n-i] * nums[n-i];
        }
        for(i=0;i<n;++i)
            res[i]*=asc[i];
        return res;
    }
};

//SC O(1) TC(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ret(n);
        ret[0] = 1;
        int product = 1;
        int i = 1;
        for(;i<n;++i)
            ret[i] = ret[i-1] * nums[i-1];
        for(i=1;i<=n;++i){
            ret[n-i]*=product;
            product *= nums[n-i];
        }
        return ret;
    }
};
