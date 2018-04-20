/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

// Heap sort + dp O(nlogk) k is the size of primes.
#define pii pair<int,int>
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp({1});
        const int m = primes.size();
        vector<int> index(m, 0);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i=0; i<m; ++i)
            pq.push({dp[index[i]]*primes[i], i});
        while(dp.size()<n){
            int ug = pq.top().first, i = pq.top().second;
            if(ug != dp.back())
                dp.push_back(ug);
            pq.pop();
            ++index[i];
            pq.push({dp[index[i]] * primes[i], i});
        }
        return dp.back();
    }
};

// Dp + loop O(kn) Similar as 264. Uglu Number II
#define pii pair<int,int>
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 1);
        const int m = primes.size();
        vector<int> index(m, 0);
        for(int i=1; i<n; ++i){
            int next = INT_MAX;
            for(int j = 0; j<m; ++j)
                next = min(next, dp[index[j]] * primes[j]);
            dp[i] = next;
            for(int j=0; j<m; ++j)
                if(next == dp[index[j]] * primes[j])
                    ++index[j];
        }
        return dp.back();
    }
};

// Faster, with a vector to store the val of multiplication
#define pii pair<int,int>
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 1);
        const int m = primes.size();
        vector<int> index(m, 0);
        vector<int> val(primes);
        --n;
        for(int i=0; i<n; ++i){
            int next = INT_MAX;
            for(int j = 0; j<m; ++j){
                if(val[j] == dp[i]){
                    val[j] = dp[++index[j]] * primes[j];
                }
                next = min(next, val[j]);
            }
            dp[i+1] = next;
        }
        return dp.back();
    }
};

//others
class Solution {
public:


    int nthSuperUglyNumber(int n, vector<int>& primes) {
        /*
        method 1: heap + dp (61 ms)

        property:
        1. big ugly number is built on smaller ugly number

        2. the value of every candidate is rec[i] * p, and all ugly numbers in rec [0 ~ i-1] * p have been found, so the next ugly number must be in
        the k candidates

        3. use heap can avoid going through all candidates to find the minimum every step  ---> avoid repeated calculations

        time: O(n * logk ~ n * k * logk)
        space: O(n + k)


        vector<int> rec(n);
        rec[0] = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        int k = primes.size();
        vector<int> idx(k);
        for(int i = 0; i < k; ++i) {
            min_heap.emplace(primes[i], i);
        }
        for(int i = 1; i < n; ++i) {
            rec[i] = min_heap.top().first;
            //there might be duplicates among the k candidates
            while(min_heap.top().first == rec[i]) {
                auto a = min_heap.top();
                min_heap.emplace(rec[++idx[a.second]] * primes[a.second], a.second);
                min_heap.pop();
            }

        }
        return rec[n-1];
        */

        /*
        method 2: list + dp (27 ms)

        time: O(n * k)
        space: O(n + k)

        property:
        1. if there are duplicates in candidates, the overhead of maintaining heap is even worse than using list


        vector<int> uglies(n);
        uglies[0] = 1;

        int k = primes.size();
        vector<int> idx(k);
        vector<int> cdns(primes);

        for(int i = 1; i < n; ++i) {
            uglies[i] = *min_element(cdns.begin(), cdns.end());
            for(int j = 0; j < k; ++j) {
                if(cdns[j] == uglies[i]) {
                    cdns[j] = uglies[++idx[j]] * primes[j];
                }
            }
        }
        return uglies[n-1];
        */

        /*
        method 3: expand from current ugly number (31 ms)

        property:
        1. always multiply current ugly number with primes that are not greater than the minimum prime factor of current ugly number  -> make every ugly number will be found exactly one time  --------> avoid duplicates in candidates

        2. but every time when we pop the minimum from the candidates heap, there can be at most k new numbers added into the heap, then the size of
        the heap can grow up to (n * k)

        3. notice integer overflow

        time: O( n * logk ~ n * k * log(n * k))
        space: O(k ~ n * k)


        int k = primes.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> uglies(n);
        uglies[0] = 1;
        for(int i = 0; i < k; ++i) {
            min_heap.emplace(primes[i], i);
        }

        for(int i = 1; i < n; ++i) {
            uglies[i] = min_heap.top().first;
            int m = min_heap.top().second;
            min_heap.pop();
            for(int j = 0; j <= m; ++j) {
                if(uglies[i] * primes[j] / primes[j] == uglies[i]) {
                    min_heap.emplace(uglies[i] * primes[j], j);
                }

            }
        }
        return uglies[n-1];
        */

        /*
        method 4: hash table (78 ms)

        property:
        1. we want to candidates set has no duplicates, and the size of the heap is O(k)

        2. when the curent ugly number uglies[i] is primes[j] * uglies[k], we check from uglies[k+1], until uglise[x] * primes[j] is not in the heap

        3. we use a hash table to record all values in the heap, because there are at most k elements in the heap, and uglies[i] must not in the heap now(because we remove it),   so for every ugly number, we only need at most k times check.

        key: how to proof that any ugly number will be found the first time by ascending prime factors list?


        vector<int> uglies(n);
        uglies[0] = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        unordered_set<int> rec;
        int k = primes.size();
        vector<int> idx(k);
        for(int i = 0; i < k; ++i) {
            min_heap.emplace(primes[i], i);
            rec.emplace(primes[i]);
        }
        for(int i = 1; i < n; ++i) {
            int j;
            tie(uglies[i], j) = min_heap.top();
            min_heap.pop();
            while(rec.count(primes[j] * uglies[idx[j]])) {
                ++idx[j];
            }
            min_heap.emplace(primes[j] * uglies[idx[j]], j);
            rec.emplace(primes[j] * uglies[idx[j]]);
        }
        return uglies[n-1];

        */


        /*
        method 5: explicitly use the ascending rule

        property:
        1. get every ugly number by multipling from small prime factors to large prime factors       ------->
            only one way to get every ugly number

        2. the next ugly number must be in the candidates heap
            proof:
            1. every ugly number belongs to exactly one group
            2. the idx[k] moves only when current ugly number is uglies[idx[k]] * primes[k], and now we try to find the next ugly number that belongs to
                this group(whose biggest factor is primes[k])
            3. for any group k, it idx[k] records the next ugly number that comes from this group, for all j < idx[i] and uglies[j] * primes[i] belongs to group i, this ugly number has been found.

                Soppose the next ugly number belongs to group x, then uglies[idx[x]] * primes[x] must be the number


        time: O(n * logk ~ n * k)
        space: O(n + k)
        */

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> uglies(n);
        uglies[0] = 1;
        vector<int> last_factor(n);
        int k = primes.size();
        vector<int> idx(k);
        for(int i = 0; i < k; ++i) {
            min_heap.emplace(primes[i], i);
        }
        for(int i = 1; i < n; ++i) {
            tie(uglies[i], last_factor[i]) = min_heap.top();
            min_heap.pop();
            int j = last_factor[i];
            ++idx[j];
            while(last_factor[idx[j]] > j) {
                ++idx[j];
            }
            min_heap.emplace(primes[j] * uglies[idx[j]], j);
        }
        return uglies[n-1];


    }
};
