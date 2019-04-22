/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/
// Regulation
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return true;
        if(isupper(word[0]) && isupper(word[1])){
            for(int i=2; i<word.size(); ++i)
                if(islower(word[i]))
                    return false;
        }else if(islower(word[0]) && isupper(word[1])){
            return false;  
        }else{
            for(int i=2; i<word.size(); ++i)
                if(isupper(word[i]))
                    return false;
        }
        return true;
    }
};

// Statistic
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper_count = 0;
        for(char w:word)
            if(isupper(w))
                ++upper_count;
        return upper_count == word.size() || upper_count == 0 || (upper_count == 1 && isupper(word[0]));
    }
};

/*
"USA"
"US"
"usa"
"U"
"USAUSA"
"uSA"
"USa"
"leetcode"
"a"
"A"
"App"
"LEETCODE"
"leetcodeleetcode"
"Google"
"A"
*/