/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard
qwertyuiop
asdfghjkl
 zxcvbnm

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> kb({
            {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'},
            {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'},
            {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'}});
        vector<string> ret;
        for(string w:words){
            int line = 0, i=1;
            if(w.size()!=0)
                for(;kb[line].find(w[0])==kb[line].end(); ++line);
            for(; i<w.size() && kb[line].find(w[i]) != kb[line].end(); ++i);
            if(i>=w.size())
                ret.push_back(w);
        }
            
        return ret;
    }
};