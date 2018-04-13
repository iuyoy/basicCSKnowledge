/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].
*/
// DP O(n^2) O(n)
// Advanced sort the pairs to reduce useless comparisons.
class Solution {
private:
    vector<int> cot;
    int n;
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        cot = vector<int>(n, 0);
        int ret = 0;
        for(int i = 0;i<n;++i)
            ret = max(dp(pairs, i), ret);
        return ret;
    }
    int dp(vector<vector<int>>& pairs, int i){
        if(cot[i]==0){
            for(int j = 0; j<n; ++j)
                if(pairs[i][1]<pairs[j][0])
                    cot[i] = max(cot[i], dp(pairs, j));
            cot[i] += 1;
        }
        return cot[i];
    }
};

// DP O(n^2) O(n)
bool comparator(vector<int> a, vector<int> b) {
    return a.front()<b.front();
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        const int n = pairs.size();
        vector<int> cot = vector<int>(n, 1);

        sort(pairs.begin(), pairs.end(), comparator);
        for(int i = 1;i<n;++i)
            for(int j = 0; j<i; ++j)
                if(pairs[j][1]<pairs[i][0])
                    cot[i] = max(cot[j]+1, cot[i]);
        int ret = 0;
        for(int score : cot)
            ret = max(ret, score);
        return ret;
    }
};

// Greedy O(nlgn + n)=O(nlgn) O(1)
bool comparator(vector<int> a, vector<int> b) {
    return a.back()<b.back();
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        const int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comparator);
        if(n == 0)
            return 0;
        int cur = pairs[0][1];
        int cot = 1;
        for(int i = 1;i<n;++i)
            if(cur < pairs[i][0]){
                ++cot;
                cur = pairs[i][1];
            }
        return cot;
    }
};
