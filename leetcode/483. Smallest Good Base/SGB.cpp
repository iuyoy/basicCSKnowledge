/*
For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.

Now given a string representing n, you should return the smallest good base of n in string format.

Example 1:
Input: "13"
Output: "3"
Explanation: 13 base 3 is 111.
Example 2:
Input: "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.
Example 3:
Input: "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.
Note:
The range of n is [3, 10^18].
The string representing n is always valid and will not have leading zeros.
*/
// BinarySearch O(log(n)logn)
#define ll unsigned long long

class Solution {
public:
    string smallestGoodBase(string n) {
        ll num = stoll(n);
        ll lo = 2, hi = num-1;
        int cot = 3;
        ll mid;
        ll k = hi;
        while(pow(2, cot-1)<=num){
            ll l = lo, r = hi;
            // cout<<cot<<" "<<hi<<endl;

            while(l<=r){
                mid = l + (r-l)/2;
                // ano = stoll(one,0,mid);
                // cout<<ano<<" "<<num<<endl;
                int rs = check(num,mid, cot);
                // cout << mid <<" "<< rs<<" "<<cot<<endl;
                if(rs == -1){
                    k = mid;
                    break;
                }
                if(rs==1)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            if(k==mid)
                hi = mid-1;
            else
                hi = l;
            ++cot;
            // cout<<lo<<" "<<hi<<endl;

        }
        return to_string(k);
    }
    int check(ll num, ll mid, int cot){
        while(num%mid == 1){
            --cot;
            num/=mid;
        }
        if(cot == 0) return -1;
        while(num>0){
            num /= mid;
            --cot;
        }
        return cot>0;
    }
};
