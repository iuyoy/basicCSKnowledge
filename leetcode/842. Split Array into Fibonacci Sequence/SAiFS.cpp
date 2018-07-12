/*
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]
Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]
Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.
Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
Note:

1 <= S.length <= 200
S contains only digits.
*/
// backtracking O()
class Solution {
private:
    vector<int> ret;
    int toInt(string s){
        long num = stol(s);
        if(num>INT_MAX)
            return -1;
        return num;
    }
    bool dfs(string S, int b, int c, int end){
        for(int i=end-1, len=1; i>=0 && len<=10; --i,++len){
            if(S[i] == '0' && len>1) continue;
            int a = toInt(S.substr(i, len));
            if(a==-1 || a+b>c)
                return false;
            if(a+b==c){
                ret.insert(ret.begin(), a);
                if(i==0 || dfs(S, a, b, i))
                    return true;
                else
                    ret.erase(ret.begin());
            }
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        if(S.size()<3) return {};
        for(int i=S.size()-1, len1=1; i>=2&&len1<=10; --i,++len1){
            if(S[i] == '0' && len1>1) continue;
            int c=toInt(S.substr(i, len1));
            if(c==-1) return {};
            ret.push_back(c);
            for(int j=i-1, len2=1; j>=1&&len2<=10; --j,++len2){
                if(S[j] == '0' && len2>1) continue;
                int b=toInt(S.substr(j, len2));
                ret.insert(ret.begin(), b);
                if(b==-1 && b>c) continue;
                if(dfs(S, b, c, j))
                    return ret;
                ret.erase(ret.begin());
            }
            ret.erase(ret.begin());
        }
        return {};
    }
};
/*
"123456579"
"11235813"
"1101111"
"0123"
"123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"000"
"123"
"101"
*/