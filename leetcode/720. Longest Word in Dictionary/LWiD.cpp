/*

Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input:
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation:
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input:
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation:
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
*/
// DFS with finger + hash O(n)
class Solution {
private:
    unordered_map<string, int> umap;
    bool signWord(string w){
        if(w.size() == 1)
            umap[w] = 1;
        else if(umap[w] == -1){
            string sub = w.substr(0, w.size()-1);
            if(umap[sub] == 1 ||(umap[sub] == -1 && signWord(sub)))
                umap[w] = 1;
            else
                umap[w] = 0;
            // cout<<sub<<endl;
            // if(umap.find(sub) == umap.end())
            //     umap[w] = 0;
            // else if(umap[sub] == 1 ||(umap[sub] == -1 && signWord(sub)))
            //     umap[w] = 1;
            // else
            //     umap[w] = 0;
        }
        return umap[w];
    }
public:
    string longestWord(vector<string>& words) {
        for(string w:words)
            umap[w] = -1;
        string ret = "";
        for(string w:words)
            if((w.size() > ret.size() || (w.size() == ret.size() && w<ret)) && 1 == signWord(w)) // Faster
            // if(signWord(w) == 1 && (w.size() > ret.size() || (w.size() == ret.size() && w<ret)))
                ret = w;
        // sort(words.begin(), words.end());
        // for(auto w:umap)
        //     cout<<w.first<<" "<<w.second<<endl;
        return ret;
    }
};
