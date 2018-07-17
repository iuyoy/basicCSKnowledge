/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.
*/
//DFS O(2^n)
class Solution {
private:
    vector<string> ret;
    void generate(string l, string r){
        if(l.size()){
            char c = l.back();
            l.pop_back();
            if('a'<=c && c<='z')
                generate(l, (char)(c+'A'-'a') + r);
            else if('A'<=c && c<='Z')
                generate(l, (char)(c+'a'-'A') + r);
            generate(l, c+r);
        }else
            ret.push_back(r);
    }
public:
    vector<string> letterCasePermutation(string S) {
        generate(S, "");
        return ret;
    }
};