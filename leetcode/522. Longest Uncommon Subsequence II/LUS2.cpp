/*

Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
*/
// Sort O(n^2*k)
class Solution {
private:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        int j = 0;
        for(int i=0;i<t.size() && j < s.size();++i)
            if(t[i] == s[j]) ++j;
        return j==s.size();
    }
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string a, string b){ return a.size() == b.size()? a>b : a.size()>b.size();});
        for(int i=0, j=0; i<strs.size(); ++i){
            if(i == strs.size()-1 || strs[i] != strs[i+1]){
                for(; j<i; ++j)
                    if(isSubsequence(strs[i], strs[j])) break;
                if(j == i)
                    return strs[i].size();
            }else
                ++i;
        }
        return -1;
    }
};
