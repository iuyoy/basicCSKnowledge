/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.


Note:

1 <= paragraph.length <= 1000.
1 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
Different words in paragraph are always separated by a space.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
*/
// Hash O(m+n) O(m+n)
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> words;
        unordered_set<string> bans;
        for(string ban : banned)
            bans.insert(ban);
        int cur = -1;// start of a word
        // Split paragrah and store and count in unordered_map<string, int> words
        for(int i=0;i<paragraph.length();++i){
            // To lowercase
            if(paragraph[i]<='Z' && paragraph[i]>='A')
                paragraph[i] -= 'Z'-'z';
            if(paragraph[i]>'z' || paragraph[i]<'a') {
                if(cur != -1)
                    ++words[paragraph.substr(cur, i-cur)];
                cur = -1;
            }else if(cur == -1){
                cur = i;
            }
        }
        if(cur != -1 && paragraph.length()>cur)
            ++words[paragraph.substr(cur, paragraph.length()-cur)];
        // Find the Most Common no-banned Word
        string ret;
        int m = -1;
        for(auto w:words){
            if(bans.find(w.first) == bans.end() && w.second>m){
                ret = w.first;
                m = w.second;
            }
        }
        return ret;
    }
};
