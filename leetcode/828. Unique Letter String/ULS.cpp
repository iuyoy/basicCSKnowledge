/*
A character is unique in string S if it occurs exactly once in it.

For example, in string S = "LETTER", the only unique characters are "L" and "R".

Let's define UNIQ(S) as the number of unique characters in string S.

For example, UNIQ("LETTER") =  2.

Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.

If there are two or more equal substrings at different positions in S, we consider them different.

Since the answer can be very large, return the answer modulo 10 ^ 9 + 7.

 

Example 1:

Input: "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:

Input: "ABA"
Output: 8
Explanation: The same as example 1, except uni("ABA") = 1.
 

Note: 0 <= S.length <= 10000.
*/

#define m 1000000007
class Solution {
public:
    int uniqueLetterString(string S) {
        int n = S.size();
        long long ret = 0;
        ++n;
        for(int i=1; i<=n; ++i)
            ret = (ret + i*(n-i))%m;
        --n;
        cout<<ret<<endl; 
        unordered_map<char, vector<int>> dups;
        for(int i=0; i<n; ++i) dups[S[i]].push_back(i);
        for(auto p:dups){
            vector<int> dup = p.second;
            int nn = dup.size();
            dup.insert(dup.begin(), -1);
            dup.push_back(n);
            for(long long i=1; i<nn; ++i)
                for(long long j=i+1; j<=nn; ++j){
                    // cout<<dup[j+1]-dup[i-1]-1-dup[j]+dup[i]<<" "<<j-i+1<<endl;
                    ret = (ret - ((dup[i]-dup[i-1])*(dup[j+1]-dup[j])%m)*(j-i+1)%m+m)%m;
                    
                }
        }
        return ret;
    }
};
/*
"AB"
"ABAB"
"ABABAB"
"ABC"
"ABA"
"AAA"
"AAAA"
"ABCD"
"ABCABCABC"
"ABABAB"
*/