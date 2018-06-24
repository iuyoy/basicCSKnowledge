/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false

*/
// Brute Force TLE
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        const int n = s1.size();
        for(int i=1; i<=n/2; ++i){
            string s11 = s1.substr(0, i), s12 = s1.substr(i, n-i), s13 = s1.substr(0, n-i), s14 = s1.substr(n-i, i);
            string s21 = s2.substr(0, i), s22 = s2.substr(i, n-i), s23 = s2.substr(0, n-i), s24 = s2.substr(n-i, i);
            if(isScramble(s11, s21) && isScramble(s12, s22))
                return true;
            if(isScramble(s11, s24) && isScramble(s12, s23))
                return true;
             if(isScramble(s13, s23) && isScramble(s14, s24))
                return true;
            if(isScramble(s13, s22) && isScramble(s14, s21))
                return true;
        }
        return false;
    }
};

// Recursive O(n^2)
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        const int n = s1.size();
        for(int i=1; i<=n/2; ++i){
            set<set<char>> con1_1({set<char>(s1.begin(), s1.begin()+i), set<char>(s1.begin()+i, s1.end())});
            set<set<char>> con1_2({set<char>(s1.begin(), s1.begin()+n-i), set<char>(s1.begin()+n-i, s1.end())});
            set<set<char>> con2_1({set<char>(s2.begin(), s2.begin()+i), set<char>(s2.begin()+i, s2.end())});
            set<set<char>> con2_2({set<char>(s2.begin(), s2.begin()+n-i), set<char>(s2.begin()+n-i, s2.end())});
            // cout<<s1.substr(0, i)<<" "<<s1.substr(i, n-i)<<endl;
            // cout<<s2.substr(0, i)<<" "<<s2.substr(i, n-i)<<endl;

            if(con1_1 == con2_1 && isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i)))
                return true;
            if(con1_1 == con2_2 && isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i)))
                return true;
             if(con1_2 == con2_2 && isScramble(s1.substr(0, n-i), s2.substr(0, n-i)) && isScramble(s1.substr(n-i, i), s2.substr(n-i, i)))
                return true;
            if(con1_2 == con2_1 && isScramble(s1.substr(0, n-i), s2.substr(i, n-i)) && isScramble(s1.substr(n-i, i), s2.substr(0, i)))
                return true;
        }
        return false;
    }
};
// Optimize
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // if(set<char>(s1.begin(), s1.end()) != set<char>(s2.begin(), s2.end())) return false;
        vector<int> cot(128, 0);
        for(char c:s1) ++cot[c];
        for(char c:s2) --cot[c];
        for(int c:cot) if(c!=0) return false;
        if(s1 == s2) return true;
        const int n = s1.size();
        for(int i=1; i<n; ++i){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i)))
                return true;
        }
        return false;
    }
};
/*
"abcdd"
"dbdac"
"a"
"a"
"aab"
"bba"
"abcde"
"caebd"
"gr"
"rg"
"great"
"rgeat"
"abb"
"bba"
"abcdefghijklmnopq"
"efghijklmnopqcadb"
"ccabcbabcbabbbbcbb"
"bbbbabccccbbbabcba"
*/