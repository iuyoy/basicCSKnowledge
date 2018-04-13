/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/
// Binary Search O(log(n-k))
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while(l<r){
            int mid = (l+r)/2;
            if(x-arr[mid]>arr[mid+k]-x)
                l = mid+1;
            else
                r = mid;
        }
        vector<int> ret(arr.begin()+l, arr.begin()+l+k);
        return ret;
    }
};
// Binary Search + Two points O(k + logn)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();
        int mid = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        vector<int> ret;
        int sm = mid-1;
        int lg = mid;
        for(;k>0;--k){
            if(sm>=0)
                if(lg<n)
                    if(x-arr[sm] > arr[lg] - x)
                        ret.push_back(arr[lg++]);
                    else
                        ret.insert(ret.begin(), arr[sm--]);
                else{
                    ret.insert(ret.begin(), arr.begin()+sm-k+1, arr.begin()+sm+1);
                    break;
                }
            else{
                ret.insert(ret.end(), arr.begin()+lg, arr.begin()+lg+k);
                break;
            }
        }
        return ret;
    }
};
