/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/

// Greedy O(n)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<vector<int>> locs(26, vector<int>(2, -1));
        for(int i=0; i<S.size(); ++i){
            int loc = S[i]-'a';
            if(locs[loc][0] == -1)
                locs[loc][0] = i;
            locs[loc][1] = i;
        }
        vector<int> ret;
        sort(locs.begin(), locs.end());
        int start = -1, end = -1;
        for(vector<int> loc:locs){
            if(loc[0] == -1) continue;
            if(loc[0]>end){
                if(end != -1)
                    ret.push_back(end-start+1);
                start = loc[0];
                end = loc[1];
            }else
                end = max(end, loc[1]);
        }
        ret.push_back(end-start+1);
        return ret;
    }
};
