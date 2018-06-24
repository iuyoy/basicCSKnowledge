/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.
*/
// Compared string by string with vector, O(n^2), O(n)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> letters(n, vector<int>(26));
        for(int i=0;i<n;++i)
            for(char w:words[i])
                letters[i][w-'a'] = 1;
        int ret = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(words[i].size()*words[j].size()>ret){
                    int k=0;
                    while(k<26 && (letters[i][k] == 0|| letters[j][k]==0)) ++k;
                    if(k==26)
                        ret = words[i].size()*words[j].size();
                }
            }
        }
        return ret;
    }
};
// Compared string by string with bitmask, O(n^2), O(n)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> letters(n);
        for(int i=0;i<n;++i)
            for(char w:words[i])
                letters[i] |= 1<<(w-'a');
        int ret = 0;
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j)
                if(words[i].size()*words[j].size()>ret && (letters[i]&letters[j])==0)
                    ret = words[i].size()*words[j].size();
        return ret;
    }
};
/*
["abcw","baz","foo","bar","xtfn","abcdef"]
["a","ab","abc","d","cd","bcd","abcd"]
["a","aa","aaa","aaaa"]
*/