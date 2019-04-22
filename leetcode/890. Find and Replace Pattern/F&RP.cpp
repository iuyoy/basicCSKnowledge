/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/
// hashmap O(mn)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for(string word:words){
            vector<int> mp(128, 0);
            vector<int> mp2(128, 0);
            int i = 0;
            for(; i< pattern.size(); ++i){
                if(mp[word[i]] == 0 && mp2[pattern[i]] == 0){
                    mp[word[i]] = pattern[i];
                    mp2[pattern[i]] = word[i];
                }
                else if(mp[word[i]] != pattern[i] || mp2[pattern[i]] != word[i])
                    break;
            }
            if(i == pattern.size()) ret.push_back(word);
        }
        return ret;
    }
};