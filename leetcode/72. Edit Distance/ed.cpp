/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
// 2-sequence DP O(mn) O(mn)
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n1 = word1.size();
        const int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        int i = 0, j = 1;
        for(;i<=n1;++i)
            dp[i][0] = i;
        for(i=0;i<=n2;++i)
            dp[0][i] = i;
        for(i=1;i<=n1;++i)
            for(j=1;j<=n2;++j)
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                     // dp[i][j] dp[i-1][j] delete i
                    // dp[i][j] dp[i][j-1] add j
                    // dp[i][j] dp[i-1][j-1] replace i with j
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]);
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                    ++dp[i][j];
                }
        return dp[n1][n2];
    }
};

//Wrong answer
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         const int n1 = word1.size(), n2 = word2.size();
//         const int n = max(n1, n2);
//         vector<int> hash(n1+1);
//         vector<int> cost(n1+1, n);
//         for(int i=0;i<n2;++i){
//             for(int j=0,m=0,ischange=0;j<n1;++j){
//                 if(ischange == 0)
//                     m = max(m, hash[j]);
//                 if(word1[j] == word2[i]){
//                     m = m + 1;
//                     hash[j+1] = m;
//                     ischange = 1;
//                     if(j>i)
//                         cost[j+1] = min(cost[j+1], n-hash[j+1]+j-i);
//                     else if(n1 + (i-j) -n2 >0)
//                         cost[j+1] = min(cost[j+1], n-hash[j+1] + n1+(i-j)-n2);
//                     else
//                         cost[j+1] = min(cost[j+1], n-hash[j+1]);
//                 }else{
//                     ischange = 0;
//                 }
//             }
//         }
//         int ret = n;
//         for(int j=0;j<=n1;++j){
//             ret = min(ret, cost[j]);
//             // cout<<cost[j]<<" "<<hash[j]<<endl;
//         }
//         return ret;
//     }
// };
