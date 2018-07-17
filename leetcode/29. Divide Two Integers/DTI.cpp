/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/
// Without bit op
// log(n)?
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(divisor == 0 || dividend == 0)
            return 0;
        bool minus = false;
        if(dividend<0){
            if(divisor>0){
                minus = true;
                divisor = -divisor;
            }
        }
        else{
            dividend =  -dividend;
            if(divisor>0)
                divisor = -divisor;
            else
                minus = true;

        }
        vector<vector<int>>bit(32, vector<int>(2, 0));
        int i = 0;
        int n = 1;

        while(dividend-divisor <= divisor){
            bit[i][0] = divisor;
            bit[i][1] = n;
            ++i;
            n += n;
            divisor += divisor;
        }
        if(dividend <= divisor){
            bit[i][0] = divisor;
            bit[i][1] = n;
        }
        int ret = 0;
        for(;i>=0; --i){
            if(dividend<=bit[i][0]){
                dividend -= bit[i][0];
                ret += bit[i][1];
            }
        }
        if(minus)
            return -ret;
        return ret;
    }
};
