/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

typedef vector<int> vi;
//DP O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vi dp(n, 0);
        for(int i=0; i<n; ++i){
            if(i>1) dp[i] = max(dp[i], dp[i-1]);
            for(int j = i+1; j<n; ++j)
                if(prices[j]>prices[i])
                    dp[j] = max(dp[j], prices[j]-prices[i] + (i>2?dp[i-2]:0));
        }
        return dp[n-1];  
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, pre_buy, pre_sell=0;
        for(int p:prices){// ith turn
            pre_buy = buy;//i-1 buy
            buy = max(pre_buy, pre_sell - p);
            //                 i buy = i-2 sell - p,
            pre_sell = sell;// i-1 sell
            sell = max(pre_sell, pre_buy + p);// i sell
        }
        return sell;
    }
};