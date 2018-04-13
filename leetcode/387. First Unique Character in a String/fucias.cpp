/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
// Hash O(n)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26, -1);
        const int n = s.length();
        for(int i = 0; i<n; ++i){
            if(hash[s[i] - 'a'] == -1)
                hash[s[i] - 'a'] = i;
            else
                hash[s[i] - 'a'] = n;
        }
        int ret = n;
        for(int i = 0; i<26; ++i)
            if(hash[i]>=0)
                ret = min(ret, hash[i]);
        return ret == n? -1:ret;
    }
};
