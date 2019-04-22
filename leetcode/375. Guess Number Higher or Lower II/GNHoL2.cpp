/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/

typedef vector<int> vi;
typedef vector<vi> vvi;
// divide and conquer with memory.
class Solution {
public:
    vvi mem;
    int cq(int start, int end){
        if(start >= end) return 0;
        if(mem[start][end] == -1){
            int res = INT_MAX;
            for(int i=start; i<=end; ++i)
                res = min(res, i + max(cq(start, i-1), cq(i+1, end)));
            mem[start][end] = res;
        }
        
        return mem[start][end];
    }
    int getMoneyAmount(int n) {
        mem = vvi(n+1, vi(n+1, -1));
        return cq(1, n);
    }
};