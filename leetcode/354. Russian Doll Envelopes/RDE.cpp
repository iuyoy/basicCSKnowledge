/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

*/
//Similar as 300. Longest Increasing Subsequence
//DP O(n^2)
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        const int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        int ret = 0;
        for(int i = 0;i<n; ++i){
            for(int j = 0; j<i; ++j){
                if(envelopes[i].first>envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

//Binary Search O(nlog(n))
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        const int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> l, pair<int, int> r)->bool{
            return l.first<r.first || (l.first==r.first&& l.second>r.second);
            // return l.first == r.first ? l.second >= r.second : l.first<r.first;
        });
        vector<int> tail;
        for(auto envelop : envelopes){
            auto where = lower_bound(tail.begin(), tail.end(), envelop.second);
            if(where == tail.end())
                tail.push_back(envelop.second);
            else
                *where = envelop.second;
        }
        return tail.size();
    }
};
