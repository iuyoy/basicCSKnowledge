/*
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input:
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
*/

//TLE
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int n = words.size();
        int result[n] = {0};
        int index[n] = {0};
        // for(int a:result)cout<<"a:"<<a<<endl;
        int i = 0;
        for(auto s:S){
            for(i=0;i<n;++i){
                if(!result[i] && words[i][index[i]]==s){
                    ++index[i];
                    if(index[i]==words[i].length()){
                        // cout<<words[i]<<endl;
                        result[i] = 1;
                    }
                }
            }
        }
        // for(int a:result)cout<<"a:"<<a<<endl;
        return count(result, result + n, 1);
    }
};

// Almost TLE but not
class Solution {
public:
    unordered_map<char, vector<string>> hash;
    int numMatchingSubseq(string S, vector<string>& words) {
        for(string w:words){
            insert_hash(w[0], w.substr(1, w.length()-1));
        }
        int c = 0;
        for(char s:S){
            if(hash.find(s) != hash.end()){
                vector<string> new_ve;
                for(auto w:hash[s]){
                    if(w[0]==0)
                        c++;
                    else if(w[0]==s)
                        new_ve.push_back(w.substr(1, w.length()-1));
                    else
                        insert_hash(w[0], w.substr(1, w.length()-1));
                }
                hash[s].clear();
                if(new_ve.empty())
                    hash.erase(s);
                else
                    hash[s] = new_ve;
            }
        }
        return c;
    }
    void insert_hash(char w, string str){
        if(hash.find(w) == hash.end())
            hash[w] = vector<string>({str});
        else
            hash[w].push_back(str);
    }
};
