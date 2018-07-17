/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

//Fixed Rule: Big Integer Likely o(nk) k is the bits of n.
class Num{
private:
    vector<int> num;
public:
    Num(int n){
        int i = 0;
        while(n>0){
            n/=10;
            ++i;
        }
        num = vector<int>(i, -1);
        num[i-1] = 1;
    }
    Num& operator++(){
        int i=0;
        while(num[i] == -1) ++i;
        if(i!=0) --i;
        ++num[i];
        while(num[i]==10){
            num[i++] = -1;
            ++num[i];
        }
        return *this;
    }
    int get(){
        int i = 1, ret = 0;
        for(auto n:num)
            if(n!=-1){
                ret += i*n;
                i*=10;
            }
        return ret;
    }
    void del1bit(){
        num.erase(num.begin());
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Num num(n);
        vector<int> ret;
        for(int i=0;i<n;++i){
            int nn = num.get();
            ret.push_back(nn);
            if(nn==n)
                num.del1bit();
            ++num;
        }
        return ret;
    }
};

// Settled Rules: almost O(n) iterative
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int i=1;
        for(int cot=0; cot<n;++cot){
            ret[cot] = i;
            if(i*10 <= n)
                i *= 10;
            else{
                if(i>=n)
                    i/=10;
                ++i;
                while(i%10 == 0) i /= 10;
            }
        }
        return ret;
    }
};


// DFS O(n)
class Solution {
private:
    void dfs(int i, int n, vector<int>& ret){
        if(i>n)
            return;
        ret.push_back(i);
        dfs(i*10, n, ret);
        if(i%10 != 9)
            dfs(i+1, n, ret);
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        dfs(1, n, ret);
        return ret;
    }
};
