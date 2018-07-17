/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/
//Greedy O(26*n) O(26)
class Solution {
  public:
    string reorganizeString(string S) {
        string ret;
        vector<int> cot(27);
        for (char c : S)
            ++cot[c - 'a'];
        while (ret.size() < S.size()) {
            int max_i = 26;
            for (int i = 0; i < 26; ++i) {
                if ('a' + i != ret.back() && cot[i] > cot[max_i])
                    max_i = i;
            }
            if (max_i == 26)
                return "";
            cot[max_i]--;
            ret.push_back(max_i + 'a');
        }
        return ret;
    }
};