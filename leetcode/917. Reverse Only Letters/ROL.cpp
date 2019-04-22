/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
*/
//Stack O(2n) O(n)
class Solution {
public:
    string reverseOnlyLetters(string S) {
        stack<char> s;
        for(char c:S)
            if(('a'<=c && c<='z') || ('A'<=c && c<='Z'))
                s.push(c);
        for(int i=0;i<S.size();++i)
            if(('a'<=S[i] && S[i]<='z') || ('A'<=S[i] && S[i]<='Z')){
                S[i] = s.top();
                s.pop();
            }
        return S;
    }
};

//Two pointers O(n) O(n)