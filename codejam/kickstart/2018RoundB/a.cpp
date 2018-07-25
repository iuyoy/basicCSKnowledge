/*
Problem
No Nine is a counting game that you can try when you are bored. In this game,
you are only allowed to say numbers that are legal. A number is legal if and
only if all of the following are true:

it is a natural number (i.e. in the set {1, 2, 3...})
it does not contain the digit 9 anywhere in its base 10 representation
it is not divisible by 9
For example, the numbers 16 and 17 are legal. The numbers 18, 19, 17.2, and -17
are not legal.

On the first turn of the game, you choose and say a legal number F. On each
subsequent turn, you say the next legal number. For example, if you played a
game with F = 16, you would say 16, 17, 20, 21, and so on.

Alice is very good at this game and never makes mistakes. She remembers that she
played a game in which the first number was F and the last number was L (when
she got tired of the game and stopped), and she wonders how many turns were in
the game in total (that is, how many numbers she said).

Input
The input starts with one line containing one integer T; T test cases follow.
Each test case consists of a single line containing two integers F and L: the
first and last numbers from the game, as described above.

Output
For each test case, output one line containing Case #x: y, where x is the test
case number (starting from 1), and y is the number of the turns played in the
game.

Limits
1 ≤ T ≤ 100.
F does not contain a 9 digit.
F is not divisible by 9.
L does not contain a 9 digit.
L is not divisible by 9.
Small dataset
1 ≤ F < L ≤ 106.
Large dataset
1 ≤ F < L ≤ 1018.
Sample

Input

Output

2
16 26
88 102

Case #1: 9
Case #2: 4

In Sample Case #1, the game lasted for 9 turns, and the numbers Alice said were:
16, 17, 20, 21, 22, 23, 24, 25, 26.

In Sample Case #2, the game lasted for 4 turns, and the numbers Alice said were:
88, 100, 101, 102.
*/

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<long> vl;
typedef long long ll;
typedef long double ld;

// Count total No Nine numbers no larger than n
long count(long n, vl dp) {
    string num = to_string(n);
    long ret = 0;
    int front = 0;
    int len = num.size() - 1;
    for (int i = 0; i < len; ++i) {
        for (int digit = num[i] - '0'; digit > 0; digit--, ++front) {
            front %= 9;
            ret += 8 * dp[len - i - 1];// conclude those sum of every digits is 9 and that digits including 9.
        }
    }
    for (int j = 0; j <= num.back() - '0' && j < 9; ++j, ++front)
        if (front % 9)
            ++ret;
    return ret;
}
void solution(long f, long l, vl dp) {
    cout << count(l, dp) - count(f, dp) + 1;
    return;
}

// the count of each sum(from 0 - 9 mod 9) of digits when there are i digits.
vl filter() {
    vl dp(19);
    dp[0] = 1;
    for (int i = 1; i < 19; ++i)
        dp[i] = 9 * dp[i - 1];
    return dp;
}

int main() {
    int t;
    long n, m;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    vl dp = filter();
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;
        cout << "Case #" << i << ": ";
        solution(n, m, dp);
        cout << endl;
    }

    return 0;
}
/*
C++:
gcc 6.3.0 (packages: gcc, g++)

g++ a.cpp -std=c++14 -pthread -O3 -o Solution
./Solution < a-test.in > at.out
./Solution < A-small-practice.in > as.out
./Solution < A-large-practice.in > al.out

g++ b.cpp -std=c++14 -pthread -O3 -o Solution
./Solution < b-test.in > bt.out
./Solution < B-small-practice.in > bs.out
./Solution < B-large-practice.in > bl.out

g++ c.cpp -std=c++14 -pthread -O3 -o Solution
./Solution < c-test.in > ct.out
./Solution < C-small-practice.in > cs.out
./Solution < C-large-practice.in > cl.out

g++ d.cpp -std=c++14 -pthread -O3 -o Solution
./Solution < d-test.in > bt.out
./Solution < D-small-practice.in > ds.out
./Solution < D-large-practice.in > dl.out

*/