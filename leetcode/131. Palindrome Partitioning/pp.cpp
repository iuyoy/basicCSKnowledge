/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/
class Solution {
public:
    vector<vector<string>> result;
    vector<vector<int>> hash1;
    vector<vector<string>> partition(string s) {
        // vector<vector<string>> result;
        int i = 0;
        int length = s.length();
        // cout << length<<endl;
        this->hash1 = vector<vector<int>>(length, vector<int>());
        for(;i<length+1/2;++i){
            checkPalidrome2(s, i, i);
            checkPalidrome1(s, i, i+1);

        }
        for(;i<length;++i){
            checkPalidrome2(s, i, length-i-1);
            checkPalidrome1(s, i, length-i-1);

        }
//         for(i=0;i<length;++i){
//             // for (vector<int> :: iterator j = this->hash1[i].begin(); j != this->hash1[i].end(); ++j)
//             //     cout << *j << " ";
//             // cout << endl;


//         }
        vector<string> ret;
        this->scan(s, 0, ret);
        return this->result;
    }
    void scan(string s, int i, vector<string> ret){
        if(i == s.length())
            this->result.push_back(ret);
        else{
            for(int j = 1; j< hash1[i].size(); ++j){
                vector<string> ret2(ret);
                ret2.push_back(s.substr(i, this->hash1[i][j]));
                scan(s, i+this->hash1[i][j], ret2);
            }
            ret.push_back(s.substr(i, this->hash1[i][0]));
            scan(s, i+1, ret);
        }
    }
    void checkPalidrome1(string s, int i, int stop){
        int length = 0;
        int j = 0;
        for(;j<stop;++j){
            if(s[i+j+1]==s[i-j]){
                length += 2;
                this->hash1[i-j].push_back(length);
            }
            else
                break;
        }
    }
    void checkPalidrome2(string s, int i, int stop){
        int length = 1;
        int j = 1;
        // hash1[i] = vector<int>();
        hash1[i].push_back(1);
        for(;j<=stop;++j){
            if(s[i+j]==s[i-j]){
                length += 2;
                this->hash1[i-j].push_back(length);
            }
            else
                break;
        }
    }
};
