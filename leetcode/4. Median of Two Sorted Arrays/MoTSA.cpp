/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
// Merge Sort Based O((m+n)/2)
class Solution {
private:
    int m;
    int n;

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        int i = 0, j = 0;
        int stop = (m+n+1)/2;
        int ret = findKthSmallestNumber(nums1, i, nums2, j, stop);
        if((m+n)%2 == 1)
            return ret;
        else
            return (ret+findKthSmallestNumber(nums1, i, nums2, j, 1))/2.0;
    }
    int findKthSmallestNumber(vector<int>& nums1, int& i, vector<int>& nums2, int& j, int stop){
        // cout<<i<<j<<endl;
        int next = 0;
        while(stop>0){
            if(i<m)
                if(j<n)
                    if(nums1[i]<=nums2[j])
                        next = nums1[i++];
                    else
                        next = nums2[j++];
                else
                    next = nums1[i++];
            else
                next = nums2[j++];
            --stop;
        }
        return next;
    }
};

// Binary Search
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         const int m = nums1.size(), n = nums2.size();
//         if(m>n)
//             return findMedianSortedArrays(nums2, nums1);
//         int l = 0, r = m, i, j;
//         int semi = (m+n+1)/2;
//
//         while(l<r){
//             i = (l+r)/2;
//             j = semi - i;
//             if(i<m && nums2[j-1]>nums1[i])
//                 l = i+1;
//             else if(i>0 && nums2[j]<nums1[i-1])
//                 r = i-1;
//             else{
//                 //all nums1 are in left
//                 if(i == m) r = nums2[j];
//                 else if(j == n)
//                 //all nums1 are in right
//                 return (double)(l+r)/2;
//             }
//
//         }
//     }
// };
