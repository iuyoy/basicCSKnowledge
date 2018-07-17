/*
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
 

Note:

1 <= N <= 10^9
*/
// compare NUMBER character numbers O(31) O(1)
class Solution{
  private:
    vector<int> *cot(int N){
        vector<int> *ret = new vector<int>(10);
        while (N){
            ++(*ret)[N % 10];
            N /= 10;
        }
        return ret;
    }

  public:
    bool reorderedPowerOf2(int N){
        int n = 1;
        vector<int> *c = cot(N);
        for (int i = 0; i < 31; ++i, n <<= 1){
            // cout<<n<<endl;
            if ((*c) == (*cot(n)))
                return true;
        }
        return false;
    }
};
/*
1
2
3
4
5
16
46
45
1024
2147483648
4294967296
*/