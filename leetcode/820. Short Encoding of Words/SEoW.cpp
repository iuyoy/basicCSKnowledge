/*
Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
Note:

1 <= words.length <= 2000.
1 <= words[i].length <= 7.
Each word has only lowercase letters.
*/
// O(n^2) O(1)
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // Sort the words by length;
        sort(words.begin(), words.end(), [](string a, string b){return a.size()>b.size();});
        int ret = words[0].size()+1;
        for(int i = 1; i<words.size(); ++i){
            int j = 0;
            for(; j<i; ++j)
                // if there is any words aboved contains this word, break;
                if(words[j].substr(words[j].size()-words[i].size()) == words[i])
                    break;
            // if not, add to rusult;
            if(j == i)
                ret += words[i].size()+1;
        }
        return ret;
    }
};

// O(nk) O(nk) HashSet
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // Build Hash set
        unordered_set<string> us(words.begin(), words.end());
        // Remove every sub string
        for(string word:us)
            for(int i=1;i<word.size();++i)
                us.erase(word.substr(i));
        int ret = 0;
        for(string word:us)
            ret += word.size()+1;
        return ret;
    }
};
// Tire -  Reverse word O(nk) O(nk)
