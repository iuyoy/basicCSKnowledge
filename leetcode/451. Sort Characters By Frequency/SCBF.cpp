/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
// Heap + hash O(max(n, klogk)) k is the number of different characters
#define umci unordered_map<char, int>
class Solution {
public:
    string frequencySort(string s) {
        umci cot;
        for(char c:s) ++cot[c];
        auto comp = [&cot](char a, char b) { return cot[a] < cot[b];};
        priority_queue<char , vector<char>, decltype(comp)> pq(comp);
        for(auto c:cot) pq.push(c.first);
        int i = 0;
        while(!pq.empty()){
            char c = pq.top();
            pq.pop();
            // cout<<c<<cot[c]<<" "<<i<<endl;
            for(int tp=i+cot[c]; i<tp; ++i)
                s[i] = c;
        }
        return s;
    }
};

// Bucket Sort + hash O(n)
#define umci unordered_map<char, int>
class Solution {
public:
    string frequencySort(string s) {
        const int n = s.size();
        umci cots;
        for(char c:s) ++cots[c];
        vector<vector<char>> bucket(n+1, vector<char>());
        for(auto cot:cots)
            bucket[cot.second].push_back(cot.first);
        string ret;
        for(int i=n; i>=0; --i)
            for(char c:bucket[i])
                ret.append(i, c);
        return ret;
    }
};
