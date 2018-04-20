/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
// Delete spaces at tail,
// Reverse the string,
// Delete spaces at tail,
// Reverse each word and delete muti continuous spaces.
class Solution {
private:
    void reverse(string& s, int start, int end){
        while(start<end){
            swap(s[start], s[end]);
            ++start;
            --end;
        }
    }
public:
    void reverseWords(string &s) {
        while(s.back() == 32)
            s.pop_back();
        reverse(s, 0, s.length()-1);
        while(s.back() == 32)
            s.pop_back();
        int n = s.length();
        int cur = 0;
        for(int i=0; i<n; ++i)
            if(s[i]==32){
                reverse(s, cur, i-1);
                cur = i+1;
                while(i<n-1 && s[i+1] == 32){
                    s.erase(s.begin()+i);
                    --n;
                }
            }
        reverse(s, cur, n-1);
    }
};
