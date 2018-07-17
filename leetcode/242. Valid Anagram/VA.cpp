/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
// Hash O(n)
// Follow up Unordered_map

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cot(128);
        for(char c:s)
            ++cot[c];
        for(char c:t)
            --cot[c];
        for(int i = 'a'; i<='z';++i)
            if(cot[i])
                return false;
        return true;
    }
};
