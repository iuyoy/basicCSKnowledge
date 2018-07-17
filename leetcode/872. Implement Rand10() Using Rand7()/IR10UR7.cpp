/*
Given a function rand7 which generates a uniform random integer in the range 1
to 7, write a function rand10 which generates a uniform random integer in the
range 1 to 10.

Do NOT use system's Math.random().



Example 1:

Input: 1
Output: [7]
Example 2:

Input: 2
Output: [8,4]
Example 3:

Input: 3
Output: [8,1,10]


Note:

rand7 is predefined.
Each testcase has one argument: n, the number of times that rand10 is called.

Follow up:

What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?
*/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
// rand2 1.164 calls to rand7() $ \frac{6}{7} * \displaystyle\sum_{i=0}^n \frac{i+1}{7^i} $
// rand5 1.227 calls to rand7()
// total 2.391 calls
class Solution {
  public:
    int rand10() {
        int judge = rand7();
        int ret = rand7();
        while (judge == 7)
            judge = rand7();
        while (ret > 5)
            ret = rand7();
        return judge % 2 ? ret : ret + 5;
    }
};