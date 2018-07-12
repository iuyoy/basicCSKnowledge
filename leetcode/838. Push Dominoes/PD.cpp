/*
There are N dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.



After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state. 

Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Note:

0 <= N <= 10^5
String dominoes contains only 'L', 'R' and '.'
*/
//Calculate with rule O(n) O(1)
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int level = 0;
        for(int i=0;i<n;++i){
            char d = dominoes[i];
            if(d == 'R'){
                level = 1;
            }else if(d == 'L'){
                if(level){
                    int j = i-level/2;
                    if(level % 2 == 0)
                        dominoes[j++] = '.';
                    for(; j<i; ++j)
                        dominoes[j] = d;
                }else
                    for(int j=i-1; j>=0 && dominoes[j]=='.'; --j)
                        dominoes[j] = d;
                level = 0;
            }else if(level > 0){
                ++level;
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};
/*
".L.R...LR..L.."
"LL.RR.LLRRLL.."
"L.LL....."
*/