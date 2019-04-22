#include <bits/stdc++.h>
using namespace std;

#define N 1000
// Union Find with Compression
int par[N];
int Find(int x) {
    int r = x;
    // find root
    while (r != par[r])
        r = par[r];
    // keep height been one
    int i = x, j;
    while (par[i] != r) {
        j = par[i];
        par[i] = r;
        i = j;
    }
    return r;
}

void mix(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx != fy) {
        par[fy] = fx;
    }
}

// vector<int>
int find(vector<int>& uf, int x){
    int ret = x;
    while(uf[ret] != ret)
        ret = uf[ret];
    int tmp;
    while(uf[x] != ret){
        tmp = uf[x];
        uf[x] = ret;
        x = tmp;
    }
    return ret;
}

void joint(vector<int>& uf, int x, int y){
    int fx = find(uf, x), fy = find(uf, y);
    if(fx != fy) 
        uf[fx] = fy;
}
