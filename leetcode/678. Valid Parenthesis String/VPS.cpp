/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/
//Greedy O(n);
class Solution {
public:
    bool checkValidString(string s) {
        int sm = 0, lg = 0;
        // int rs = 0, rl = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '('){
                ++sm;
                ++lg;
            }else if(s[i] == ')'){
                if(lg<=0)
                    return false;
                --lg;
                if(sm>0)
                    --sm;
            }else if(s[i] == '*'){
                if(sm>0)
                    --sm;
                ++lg;
            }
        }
        return sm == 0;
    }
};
