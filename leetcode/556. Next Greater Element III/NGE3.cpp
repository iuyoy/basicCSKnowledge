/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:

Input: 12
Output: 21
 

Example 2:

Input: 21
Output: -1
*/
// String swap and sort O(N) N is the bits of n.
class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int fs = num.size()-2;//first_small
        for(;fs>=0 && num[fs+1]<=num[fs];--fs);
        if(fs<0) return -1;
        int sl=fs+1;// smallest larger
        for(;sl<num.size()&&num[fs]<num[sl];++sl);
        swap(num[fs++], num[--sl]);
        sort(num.begin()+fs, num.end());
        long ret = stol(num);
        if(ret>INT_MAX) return -1;
        return ret;
    }
};
/*
12
21
123
132
1234
1523
1324
673287
23782378
2147483647
2147483640
2144444443
2100000002
*/