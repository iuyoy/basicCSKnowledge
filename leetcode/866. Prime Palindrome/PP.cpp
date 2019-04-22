/*
Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:

Input: 6
Output: 7
Example 2:

Input: 8
Output: 11
Example 3:

Input: 13
Output: 101
 

Note:

1 <= N <= 10^8
The answer is guaranteed to exist and be less than 2 * 10^8.
*/
// genreate palindrome and check
class Solution {
private:
    int getL(int N){
        int l = 10;
        while(N/l){
            l *= 10;
        }
        return l/10;
    }
    bool isPrime(int n){
        // Corner case
        if (n <= 1)
            return false;

        // Check from 2 to n-1
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;

        return true;
    }
    int brute(int a, int b, int sum, int N){
        if(a<b)
            if(isPrime(sum) && sum>=N)
                return sum;
            else
                return 0;
        for(int n=0; n<10; ++n){
            if(a == b){
                int new_sum = sum + n*a;
                if(isPrime(new_sum) && new_sum>=N)
                    return new_sum;
            }else{
                int new_sum = sum + n*a + n*b;
                int ret = brute(a/10, b*10, new_sum, N);
                if(ret)
                    return ret;
            }
        }
        return 0;
    }
public:
    int primePalindrome(int N) {
        int l = getL(N);
        // cout<<l<<endl;

        if(l==1)
            for(int ret = N; ret<=11; ++ret)
                if(isPrime(ret))
                    return ret;
        vector<int> nums({1,3,7,9});
        for(int s=l;s<=1000000000;s=s*10){
            for(int n:nums){
                int sum = n*s + n;
                // cout<<sum<<endl;
                int ret = brute(s/10, 10, sum, N);
                if(ret)
                    return ret;
            }
        }
        return 100030001;
    }
};