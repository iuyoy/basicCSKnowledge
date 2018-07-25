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

const int oo = (int)1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
    if (fabs(a - b) < eps)
        return 0;
    return a > b ? 1 : -1;
}
void coutVi(vi vec) {
    for (auto ele : vec)
        cout << ele;
}
// Small Solution
// void solution(int n, int k, long p, vi a, vi b, vi c) {
//     p = p - 1;
//     vi ret(n, -1);
//     for (int i = 0; i < k; ++i)
//         ret[a[i] - 1] = c[i];
//     for (int i = n-1; i >= 0; --i) {
//         if (ret[i] == -1) {
//             ret[i] = (p & 1);
//             p >>= 1;
//         }
//     }
//     coutVi(ret);
//     return;
// }
void solution(int n, int k, long p, vi a, vi b, vi c) {
    
}

int main() {
    int t, n, k;
    long p;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> k >> p;
        vi A(k), B(k), C(k);
        for (int i = 0; i < k; ++i)
            cin >> A[i] >> B[i] >> C[i];
        cout << "Case #" << i << ": ";
        solution(n, k, p, A, B, C);
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
