/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

// BT tle
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size() && p.size()){
            if(p.size()>1 && p[1] == '*' && isMatch(s, p.substr(2, p.size()-2)) )
                return true;
            if(s.front() == p.front() || p.front() == '.')
                if(p.size()>1 && p[1] == '*')
                    return isMatch(s.substr(1, s.size()-1), p.substr(2, p.size()-2)) || isMatch(s.substr(1, s.size()-1), p);
                else
                    return isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
            return false;   
        }else if(s.size() == 0 && p.size() == 0)
            return true;
        else if(p.size()>1 && p[1] == '*')
            return isMatch(s, p.substr(2, p.size()-2));
        return false;
            
    }
};

// DP O(mn)
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i=1; p[i] =='*' ;i+=2)
            dp[0][i+1] = true; 
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j){
                 if(p[j-1] == '*'){
                    if( j>1 && (dp[i][j-2] ||(dp[i-1][j] || dp[i-1][j-1] || dp[i-1][j-2]) && (p[j-2] == '.' || p[j-2] == s[i-1])))
                        dp[i][j] = true;
                    else if(j>1 && (dp[i-1][j-2] && j<m && s[i-1] == p[j]))
                        dp[i][j+1] = true;
                }else if(dp[i-1][j-1] && (p[j-1] =='.' || p[j-1] == s[i-1]))
                    dp[i][j] = true;
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
               
        return dp[n][m];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i=1; p[i] =='*' ;i+=2)
            dp[0][i+1] = true; 
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j){
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    if(s[i-1] == p[j-2] || p[j-2] == '.')
                        dp[i][j] = dp[i][j-2] || dp[i-1][j];
                    else 
                        dp[i][j] = dp[i][j-2];
            }
               
        return dp[n][m];
    }
};

/*
"aa"
"a"
"aa"
"a*"
"ab"
".*"
"aab"
"c*a*b*"
"mississippi"
"mis*is*p*."
"a"
"ab*"
"bbbba"
".*a*a"
"aaaaaaaaaaaaab"
"a*a*a*a*a*a*a*a*a*a*c"
"ab"
".*.."
*/