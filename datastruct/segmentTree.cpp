#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

const int max_n = 1 << 17;

// Global array to store segment tree
int n, dat[2 * max_n - 1];
// Init ST
void init(int n_) {
    n = 1; // to simplify, set n to the power of 2.
    while (n < n_)
        n *= 2;
    for (int i = 0; i < 2 * n - 1; i++)
        dat[i] = INT_MAX;// Init all value to INT_MAX
}
// Update dat[k] to a
void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}
// query the min value from [a, b), k is the node no, [l, r) means the interval of these nodes.
// query(a, b, 0, 0, n);
int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) 
        return INT_MAX;
    if (a <= l && r <= b)
        return dat[k];
    else {
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
}