/*
We have a sorted set of digits D, a non-empty subset of {'1','2','3','4','5','6','7','8','9'}.  (Note that '0' is not included.)

Now, we write numbers using these digits, using each digit as many times as we want.  For example, if D = {'1','3','5'}, we may write numbers such as '13', '551', '1351315'.

Return the number of positive integers that can be written (using the digits of D) that are less than or equal to N.

 

Example 1:

Input: D = ["1","3","5","7"], N = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
Example 2:

Input: D = ["1","4","9"], N = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits of D.
 

Note:

D is a subset of digits '1'-'9' in sorted order.
1 <= N <= 10^9
*/
// count and delete invalid.
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> dp({1});
        vector<int> bigger({0});
        vector<bool> same({false});
        int temp = N, m = D.size();
        int n = 0, ret = 0;
        while(temp>0){
            ++n;
            int last = temp%10;
            int big = 0;
            bool sm = false;
            for(string d:D)
                if(d[0]-'0'>last)
                    ++big;
                else if(d[0]-'0' == last)
                    sm = true;
            bigger.push_back(big);
            same.push_back(sm);
            temp /= 10;
            dp.push_back( dp.back() * m );
        }
        int sm = true;
        for(int i=n; i>0; --i){
            ret += dp[i];
            if(sm){
                ret -= bigger[i]*dp[i-1];
                sm = same[i];
            }
        }
        return ret;
    }
};