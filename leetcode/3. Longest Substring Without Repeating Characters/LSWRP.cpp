/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
            */

// slide window with next occurs hashmap, O(n^2)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        vector<vector<int>> loc(128, vector<int>());
        for(int i=0; i<s.size(); ++i)
            loc[s[i]].push_back(i);
        vector<int> next(s.size(), s.size());
        for(auto c:loc){
            int i=0;
            for(; i+1<c.size(); ++i){
                next[c[i]] = c[i+1];
            }
        }
        int ret = 0;
        int start = 0;
        int last = 0;
        int end = next[0];
        for(int i=0; i<s.size(); ++i){
            if(i == end){
                ret = max(ret, end - start);
                ++last;
                start = last;
                i = start;
                end = next[start];
            }else if(next[i] < end){
                end = next[i];
                last = i;
            }   
        }
        ret = max(ret, end - start); 
        return ret;
    }
};

// sliding window with visited status.O(2n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int ret = 0;
        int l = 0, r = 0;
        vector<int> visited(128, 0);
        for(; r<n; ++r){
            if(visited[s[r]] == 0){
                visited[s[r]] = 1;
                ret = max(ret, r-l+1);
            }else{
                for(;s[l] != s[r]; ++l)
                    visited[s[l]] = 0;
                ++l;
            }
        }
        return ret;
    }
};

// slide window with pre occurs hashmap, O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ret = 0;
        vector<int> pre(128, 0);
        for(int l = 0, r = 0; r<n; ++r){
            l = max(l, pre[s[r]]);
            ret = max(ret, r-l+1);
            pre[s[r]] = r+1;
        }
        return ret;
    }
};
/*
"pwwkew"
"sdfnweiofhoiwjiosfoia"
"fqwejhiodfjgoifhvoivipcmqhxioqjervuretuvppcoi"
"xjpoietiowehtkldnfgiuahfiupwejoigtnlkfdguibnlcv"
"dhfuweperoiptuifnjkcvblkjgiuoepoj"
"zxcvnjkmvbxjkhuieqhipowieptpiodfgodkk"
*/