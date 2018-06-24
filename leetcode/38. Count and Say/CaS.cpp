/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        string next = "";
        for(int i=1; i<n; ++i){
            int cot = 1;
            char cur = ret[0];
            for(int j=1; j<ret.size(); ++j){
                if(ret[j] == cur)
                    ++cot;
                else{
                    string c = to_string(cot);
                    next.insert(next.end(), c.begin(), c.end());
                    next.push_back(cur);
                    cot = 1;
                    cur = ret[j];
                }
            }
            string c = to_string(cot);
            next.insert(next.end(), c.begin(), c.end());
            next.push_back(cur);
            ret = next;
            next = "";
            // cout<<ret<<endl;
        }
        return ret;
    }
};
