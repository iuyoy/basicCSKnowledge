#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;

typedef vector<ll> vll;
typedef vector<long> vl;
typedef long double ld;

const int oo = (int)1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;
const int mod = 1e9 + 7;

inline int comp(const double &a, const double &b) {
    if (fabs(a - b) < eps)
        return 0;
    return a > b ? 1 : -1;
}
// Xi = (A × Xi-1 + B × Xi-1 + C) modulo D
void generateList(vl &X, long X0, long X1, int N, long A, long B, long C,
                  long D) {
    X[0] = X0;
    X[1] = X1;
    for (int i = 2; i < N; ++i)
        X[i] = (A * X[i - 1] + B * X[i - 2] + C) % D;
}
void coutVi(vi vec) {
    for (auto ele : vec)
        cout << ele;
}

void solution() {
    cout << "";
    return;
}

int main() {
    int t, n, m;
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        cin >> n >> m;
        cout << "Case #" << z << ": ";
        solution();
        cout << endl;
    }

    return 0;
}
/*

g++ a.cpp -std=c++14 -pthread -O3 -o a
./a < a-test.in > at.out
./a < A-small-attempt0.in > as.out
./a < A-small-practice.in > as.out
./a < A-large-practice.in > al.out

g++ b.cpp -std=c++14 -pthread -O3 -o b
./b < b-test.in > bt.out
./b < B-small-attempt0.in > bs.out

./b < B-small-practice.in > bs.out
./b < B-large-practice.in > bl.out

g++ c.cpp -std=c++14 -pthread -O3 -o c
./c < c-test.in > ct.out
./c < C-small-attempt0.in > cs.out

./c < C-small-practice.in > cs.out
./c < C-large-practice.in > cl.out

g++ d.cpp -std=c++14 -pthread -O3 -o d
./d < d-test.in > bt.out
./d < D-small-attempt0.in > ds.out

./d < D-small-practice.in > ds.out
./d < D-large-practice.in > dl.out

*/
