/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
// DFS TLE
// DP O(n1*n2) o(n1*n2)
class Solution {
private:
    int n1;
    int n2;
    int n3;
    vector<vector<bool>> dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length(); n2 = s2.length(); n3 = s3.length();
        dp = vector<vector<bool>>(n1+1, vector<bool>(n2+1, true));
        return pair(s1, s2, s3, 0, 0, 0);
    }
    bool pair(string s1, string s2, string s3, int i, int j, int k){
        if(k<n3){
            if(i<n1 && s1[i] == s3[k])
                if(pair(s1, s2, s3, i+1, j, k+1) && dp[i+1][j])
                    return true;
            if(j<n2 && s2[j] == s3[k] && dp[i][j+1])
                if(pair(s1, s2, s3, i, j+1, k+1))
                    return true;
        }
        if(k==n3 && j == n2 && i == n1)
            return true;
        dp[i][j] = false;
        // cout << i<<" "<<j<<endl;
        return false;
    }
};
