/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/


// Union find with weight, around O(n+m), n is node number, m is query number
typedef pair<int, double> pid;
class Solution {
public:
    vector<pid> uf;
    void joint(int a, int b, double val){ 
        pid aa = find(a);
        pid bb = find(b);
        uf[aa.first].first = bb.first;
        uf[aa.first].second = val*bb.second/aa.second;
    }
    pid find(int i){
        double val = 1;
        while(uf[i].first != i){
            val *= uf[i].second;
            i = uf[i].first;
        }
        return {i, val};
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string, int> idx;
        for(int i=0; i<n; ++i){
            string a = equations[i][0], b = equations[i][1];
            if(idx.find(a) == idx.end()){
                idx[a] = uf.size();
                uf.push_back({uf.size(), 1.0});
            }
            if(idx.find(b) == idx.end()){
                idx[b] = uf.size();
                uf.push_back({uf.size(), 1.0});
            }
            joint(idx[a], idx[b], values[i]);
        }

        vector<double> ret;
        for(vector<string> q:queries){
            if(idx.find(q[0]) != idx.end() && idx.find(q[1]) != idx.end()){
                pid a = find(idx[q[0]]);
                pid b = find(idx[q[1]]);
                if(a.first == b.first)
                    ret.push_back(a.second/b.second);
                else
                    ret.push_back(-1.0);
                    
            }else
                ret.push_back(-1.0);
        }
        return ret;
    }
};

/*
[["a","b"],["b","c"]]
[2.0,3.0]
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
[["a","b"],["b","c"],["a","d"],["a","e"]]
[2.0,3.0,4.0, 5.0]
[["a","c"],["b","a"],["a","d"],["a","e"],["x","x"]]
[["a","b"],["c","d"]]
[1.0,1.0]
[["a","c"],["b","d"],["b","a"],["d","c"]]
*/