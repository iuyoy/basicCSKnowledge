/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

// judging from center to both sides.
// O(n^2)

class Solution {
public:
    pair<int, int> isPalindromw(string& s, int l, int r){
        for(;l>=0 && r<s.size() && s[l] == s[r]; --l,++r);
        return {l+1, r-1};
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";
        pair<int, int> longest({0, 0});
        for(int i=0; i<n; ++i){
            pair<int, int> odd = isPalindromw(s, i-1, i+1);
            if(odd.second - odd.first >longest.second - longest.first) longest = odd;
            pair<int, int> even = isPalindromw(s, i, i+1);
            if(even.second - even.first >longest.second - longest.first) longest = even;
        }
        return s.substr(longest.first, longest.second - longest.first+1);
    }
    
};