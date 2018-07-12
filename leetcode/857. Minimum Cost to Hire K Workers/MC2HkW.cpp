/*
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

 

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 
 

Note:

1 <= K <= N <= 10000, where N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10^-5 of the correct answer will be considered correct.
*/
// max_heap O(nlogn) O(n)
// The main idea is if we choose k workers, the unit price is the largest wage[i]/quality[i] 
// and the result is the sum of quality * unit price.
// So we sort all unit price, find the min sum under a specific unit price.
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double ret = 1e30;
        int n = quality.size();
        vector<vector<double>> worker(n);
        for(int i=0; i<n; ++i) worker[i] = {(double)wage[i]/quality[i], quality[i]};
        sort(worker.begin(), worker.end());
        priority_queue<int> pq;
        int total = 0;
        for(int i=0;i<n;++i){
            if(i<K){
                total += worker[i][1];
                pq.push(worker[i][1]);
            }else{
                ret = min(total*worker[i-1][0], ret);
                total += worker[i][1] - pq.top();
                pq.pop();
                pq.push(worker[i][1]);
            }
        }
        return min(total*worker[n-1][0], ret);
    }
};
/*
[10,20,5]
[70,50,30]
2
[3,1,10,10,1]
[4,8,2,2,7]
3
[3,1,10,10,1]
[4,8,5,2,7]
3
[3,1,10,10,1]
[4,8,5,2,7]
4
[3,1,10,10,1]
[4,8,5,2,7]
1
*/