/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
// calculate the gap. O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(n == 0 || numRows <= 1) return s;
        int gap = (numRows-1)*2;
        string ret;
        for(int i=0; i<numRows && i<n; ++i)
            for(int j=i, g = i*2; j<n; j+=g){
                ret.push_back(s[j]); 
                if(g != gap)
                    g = gap - g;
            }
        return ret;
    }
};