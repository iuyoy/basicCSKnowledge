/*
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
*/
// Greedy O(m+n) <= 500100
// Follow up:
// Storing every character index of t in a hash,
// Comparing index of last character in c and current, by binary search
// 1B * O(n*log(m)) + O(m) VS 1B * O(m+n)
// n*log(m) <= 100*log2(500000) = 1800 VS m+n = 500100
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        const int n = t.size();
        for(char c:s){
            for(;j<n && c!=t[j];++j);
            if(j==n)
                return false;
            ++j;
        }
        return true;
    }
};
