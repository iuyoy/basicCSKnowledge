/*
Problem
You are participating in the Grand Kickstart Lucky Dip with many fantastic and
amazing prizes (and some not so good ones)!

In this Lucky Dip, there is a bag with N items. The i-th item in the bag has
value Vi. You will put your hand into the bag and draw one item at random; all
items in the bag have an equal probability of being chosen. The organizers want
contestants to feel that they have some element of choice, so after you draw an
item, you can either keep it, or "redip" by returning it to the bag and drawing
again. (Note that the returned item is now just as likely to be chosen as any of
the other items in the bag.) You may only redip a maximum of K times. If you use
K redips, you must keep the item that you draw on your (K + 1)-th draw.

If you play optimally to maximize the value of the item you will end the game
with, what is the expected value of that item?

Input
The input starts with one line containing one integer T: the number of test
cases. T test cases follow.

Each test case consists of two lines. The first line consists of two integers N
and K: the number of items in the bag, and the maximum number of times you may
redip. The second line consists of N integers Vi, each representing the value of
the i-th item.

Output
For each test case, output one line containing Case #x: y, where x is the test
case number (starting from 1) and y is the expected value described above. Your
answer will be considered correct if it is within an absolute or relative error
of 10-6 of the correct answer. See the FAQ for an explanation of what that
means, and what formats of real numbers we accept.

Limits
1 ≤ T ≤ 100.
1 ≤ Vi ≤ 109.
1 ≤ N ≤ 20000.
Small dataset
0 ≤ K ≤ 1.
Large dataset
0 ≤ K ≤ 50000.
Sample

Input

Output

5
4 0
1 2 3 4
3 1
1 10 1
3 15
80000 80000 80000
1 1
10
5 3
16 11 7 4 1

Case #1: 2.500000
Case #2: 6.000000
Case #3: 80000.000000
Case #4: 10.000000
Case #5: 12.358400


In Sample Case #1, you cannot redip, so the expected value is just the mean of
the items in the bag which is (1 + 2 + 3 + 4) / 4 = 2.5.

In Sample Case #2, the best strategy is to keep the item of value 10 if you get
it, and redip otherwise. The chance of getting that item (on either the first or
second draw) is 1 - (2/3)2 = 5/9, hence the expected value is (5/9 * 10) + (4/9
* 1) = 6.

In Sample Case #3, since all the items have the same value, it does not matter
how many times you redip and hence the expected value is 80000.

Note that cases #3 and #5 would not appear in the Small dataset.
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
typedef vector<vector<int>> vii;
typedef long long ll;
typedef long double ld;

// void solution(int n, int k, vector<int> nums) {
//     int m = 0;
//     int c = 0;
//     long long sum = 0;
//     for (int i : nums) {
//         if (i > m) {
//             c = 1;
//             m = i;
//         } else if (i == m)
//             ++c;
//         sum += i;
//     }
//     float ret = 0, base = ((float)n - c) / n;
//     float cb = 1;
//     for (int i = 0; i < k; ++i) {
//         ret += cb;
//         cb *= base;
//     }
//     cout << sum << " " << base << " " << m<<" "<<c<< endl;
//     printf("%f", ret * c * m / n + cb * sum / n);
//     return;
// }
// DP by classical probability with binSearch
// If the current value is larger than the last explanation then stop redipping.
void solution(int n, int k, vd nums) {
    sort(nums.begin(), nums.end());
    vector<long long> sum(n + 1);
    int m = nums.back();
    for (int i = 0; i < n; ++i)
        sum[i + 1] = sum[i] + nums[i];
    double ret = 0;
    for (int i = 0; i <= k; ++i) {
        int dis =
            distance(nums.begin(), lower_bound(nums.begin(), nums.end(), ret));
        ret = dis * ret / n + ((double)sum[n] - sum[dis]) / n;
    }
    printf("%f", ret);
    return;
}

int main() {
    int t, n, k;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> k;
        vd nums(n);
        for (int j = 0; j < n; ++j)
            cin >> nums[j];
        cout << "Case #" << i << ": ";
        solution(n, k, nums);
        cout << endl;
    }

    return 0;
}
/*
C++:
gcc 6.3.0 (packages: gcc, g++)
g++ b.cpp -std=c++14 -pthread -O3 -o Solution
./Solution < b-test.in > bt.out
./Solution < B-small-practice.in > bs.out
./Solution < B-large-practice.in > bl.out

*/
