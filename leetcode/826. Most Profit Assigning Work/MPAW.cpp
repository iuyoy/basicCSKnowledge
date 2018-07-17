/*
We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 

Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 

Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.

What is the most profit we can make?

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100 
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately.
Notes:

1 <= difficulty.length = profit.length <= 10000
1 <= worker.length <= 10000
difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
*/
// Sort Greedy BinarySearch O(nlogN + n + mlog(uniqueN)) O(n): n is the number of job, m is the number of workers, 
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n = difficulty.size();
        vector<pair<int, int>> cost(n);
        for(int i=0;i<n;++i) cost[i] = {difficulty[i], profit[i]};
        sort(cost.begin(), cost.end());
        int dif = cost[0].first, fit = cost[0].second;
        for(auto it=cost.begin()+1; it!=cost.end();){
            if(it->second>fit){
                if(it->first>dif){
                    fit = it->second;
                    dif = it->first;
                    ++it;
                }
                else{
                    fit = it->second;
                    cost.erase(it-1);
                }
            }else{
                cost.erase(it);
            }
        }
        int ret = 0;
        for(int w:worker){
            auto find = upper_bound(cost.begin(), cost.end(), make_pair(w, INT_MAX));
            if(find!=cost.begin())
                ret += (find-1)->second;
        }
        return ret;
    }
};