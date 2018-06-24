/*
Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: "x=x"
Output: "Infinite solutions"
Example 3:
Input: "2x=x"
Output: "x=0"
Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"
Example 5:
Input: "x=x+2"
Output: "No solution"
*/

// Specific Rules O(n) O(1)
class Solution {
public:
    string solveEquation(string equation) {
        int x = 0;
        int y = 0;
        bool left = true;
        bool add = true;
        int cur = 0;
        for(int i=0; i<equation.size(); ++i){
            if( equation[i]>='0' && equation[i]<='9'){
                cur*=10;
                cur += equation[i]-'0';
            }
            else if( equation[i] == 'x'){
                if(cur == 0 && (i==0 || equation[i-1]!='0')) cur = 1;
                x += left==add ? cur:-cur;
                cur = 0;
            }
            else if( equation[i] == '-'){
                y += left==add ? cur:-cur;
                add = false;
                cur = 0;
            }
            else if( equation[i] == '+'){
                y += left==add ? cur:-cur;
                add = true;
                cur = 0;
            }
            else if( equation[i] == '='){
                y += left==add ? cur:-cur;
                left = false;
                add = true;
                cur = 0;
            }
        }
        y += left==add ? cur:-cur;
        // cout<<y<<"/"<<x<<endl;
        if(x==0)
            if(y==0)
                return "Infinite solutions";
            else
                return "No solution";
        return "x="+to_string(-y/x);
    }
};
/*
"x+5-3+x=6+x-2"
"x=x"
"2x=x"
"2x+3x-6x=x+2"
"x=x+2"
"1=1"
"x=-1"
"x=-2147483648"
"0x=0"
*/
