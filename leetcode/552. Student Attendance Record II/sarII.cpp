/*
Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:
Input: n = 2
Output: 8
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times.
Note: The value of n won't exceed 100,000.
*/
// DP
class Solution {
public:
    int checkRecord(int n) {
        if(n<1)
            return 0;
        const long int m = 1000000007;
        long a1 = 1, a2 = 0, l1 = 1, l2 = 0, l3 = 0, g = 1, total = 3;
        long l1a = 0, l2a = 0, pa = 0;
        long ret = 3;
        for(int i = 2;i<=n;++i){
            l3 = (l3*3%m + l2)%m;
            long tl2 = l2;
            l2 = l1;
            l1 = ((ret - (l1 + tl2)%m)%m+m)%m;

            long na = ((l1a + l2a)%m + pa)%m;
            a2 = (a2*3%m + (a1 + na)%m)%m;
            long ta = a1;
            a1 = (ret - (a1 + na)%m)%m;
            long tpa = pa;
            pa = (ta+na)%m;
            l2a = l1a;
            l1a = (ta+tpa)%m;

            total = total*3%m;
            ret = ((total - (a2 + l3)%m)%m+m)%m;
            // cout<<a1<<" "<<a2<<" "<<g<<" "<<ret<<endl;
            // cout<<pa<<" "<<l1a<<" "<<l2a<<" "<<na<<endl;
            // cout<<l1<<" "<<l2<<" "<<" "<<l3<<" "<<total<<endl;
        }
        return ret;
    }
};
