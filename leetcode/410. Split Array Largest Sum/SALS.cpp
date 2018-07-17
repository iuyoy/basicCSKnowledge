/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/

// DP O(n^3)
class Solution {
public:
    int splitArray(vector<int>& A, int k) {
        vector<double> a(A.begin(), A.end());
        a.insert(a.begin(), 0);
        int n = a.size();
        vector<double> s(n, 0);
        for (int i=1; i<n; ++i) s[i] = s[i-1]+a[i];
        // partial_sum(a.begin(), a.end(), s.begin(), 0.0);


        vector<vector<double>> f(n+1, vector<double>(k+1, s[n-1]));
        for (int i=1; i<n; ++i) f[i][1] = s[i];
        for (int i=2; i<n; ++i)
            for (int j=2; j<=min(i,k); ++j)
                for (int p=0; p<i; ++p)
                    f[i][j] = min(f[i][j], max(f[p][j-1], (s[i]-s[p])));
        return f[n-1][k];
    }
};

// Binary Search + Greeky O(log(sum-max)*n)
class Solution {
private:
    int n;
    int split(vector<int>& nums, int mid){
        int current = 0;
        int cot = 1;
        for(int i = 0; i<n; ++i){
            if(current+nums[i]>mid){
                ++cot;
                current = nums[i];
            }
            else
                current += nums[i];
        }
        return cot;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        n = nums.size();
        int l = INT_MIN, r = 0;
        for(int i = 0; i<n; ++i){
            l = max(l, nums[i]);
            r += nums[i];
        }
        while(l<=r){
            int mid = l+(r-l)/2;
            if(split(nums, mid) <= m)
                r = mid-1;
            else
                l = mid+1;
        }
        return l;
    }
};
