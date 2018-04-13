/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
// DP - CS:O(n^2) TS:O(n)
class Solution {
public:
    vector<vector<int>> hash;
    int minCut(string s) {
        // vector<vector<string>> result;
        int i = 0;
        int n = s.length();
        this->hash = vector<vector<int>>(n, vector<int>());
        for(;i<n-1;++i){
            checkPalidrome(s, i, i+1, 0);
            if(i>0)
                checkPalidrome(s, i-1, i+1, 1);
        }
        int dis[n+1]={0};
        for(i=0;i<n;i++)
            dis[i] = n-i;
        for(i=n-2;i>=0;--i){
            for(auto d:hash[i])
                dis[i] = min(1+dis[i+d], dis[i]);
            dis[i] = min(1+dis[i+1], dis[i]);

        }
        return dis[0]-1;
    }

    void checkPalidrome(string s, int a, int b, int length){
        int j = 0;
        for(;a-j>=0&&s[b+j]!=0;++j){
            if(s[a-j]==s[b+j]){
                length += 2;
                this->hash[a-j].push_back(length);
            }
            else
                return;
        }
    }
};
