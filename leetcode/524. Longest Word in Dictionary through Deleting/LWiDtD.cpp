/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/
// O(n*m) O(m)
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ret = "";
        const int n = d.size();
        vector<int> is(n);

        for(char c : s){
            for(int i = 0; i<n; ++i){
                if(d[i].size()>=ret.size() && is[i]<d[i].size() && d[i][is[i]] == c){
                    ++is[i];
                    if(is[i] == d[i].size()){
                        if(is[i]==ret.size())
                            ret = min(ret, d[i]);
                        else
                            ret = d[i];
                    }
                }
            }
        }
        return ret;
    }
};
