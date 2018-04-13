/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/
//O(n^2) O(n)
class Solution {
public:
    vector<vector<int>> hash;
    int countSubstrings(string s) {
        int i = 0;
        const int n = s.length();
        this->hash = vector<vector<int>>(n, vector<int>());
        for(;i<n-1;++i){
            checkPalidrome(s, i, i+1, 0);
            if(i>0)
                checkPalidrome(s, i-1, i+1, 1);
        }
        int ret = n;
        for(i=0;i<n;++i)
            for(auto d:hash[i])
                ++ret;
        return ret;
    }
    void checkPalidrome(string s, int a, int b, int length){
        int j = 0;
        for(;a-j>=0&&s[b+j]!=0;++j){
            if(s[a-j]==s[b+j]){
                length += 2;
                this->hash[a-j].push_back(length);
            }
            else
                return;
        }
    }
};
