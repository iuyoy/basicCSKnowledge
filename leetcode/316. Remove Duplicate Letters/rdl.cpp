/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Credits:
*/
// O(n)?
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> countChar(26, 0);
        vector<bool> isVisited(26, false);
        string ret = "0";// Avoiding emptyString;
        for(char c:s)
            ++countChar[c-'a'];
        for(char c:s){
            --countChar[c-'a'];
            if(isVisited[c-'a'])
                continue;
            while(ret.back()>c && countChar[ret.back()-'a']){
                isVisited[ret.back()-'a'] = false;
                ret.pop_back();
            }
            ret.push_back(c);
            isVisited[c-'a'] = true;
        }
        return ret.substr(1);
    }
};
