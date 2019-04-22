/*

We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a. 

Return a list of all universal words in A.  You can return the words in any order.

 

Example 1:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]
Example 3:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]
Example 4:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]
Example 5:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]
 

Note:

1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length <= 10
A[i] and B[i] consist only of lowercase letters.
All words in A[i] are unique: there isn't i != j with A[i] == A[j].
*/

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

// calculate the maximum of each character of B, compare each word in A and the max-numbers.
// O((m+n)*26)
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vi counts(26, 0);
        for(int i=0;i<B.size(); ++i){
            vi cot(26, 0);
            for(char c:B[i])
                cot[c-'a']++;
            for(int j=0;j<26;++j)
                counts[j] = max(counts[j], cot[j]);
        }
        vs ret;
        for(string s:A){
            vi cot(26, 0);
            for(char c:s)
                cot[c-'a']++;
            int i = 0;
            for(;i<26;++i)
                if(counts[i] > cot[i])
                    break;
            if(i == 26) ret.push_back(s);
        }
        return ret;
    }
};