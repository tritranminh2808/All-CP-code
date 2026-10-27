#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct pl {
    ll sum, pre, suf, val;
    pl(): sum(0), pre(LLONG_MIN/4), suf(LLONG_MIN/4), val(LLONG_MIN/4) {}
    pl(ll x): sum(x), pre(x), suf(x), val(x) {}
};

pl mergePL(const pl &L, const pl &R){
    pl C;
    C.sum = L.sum + R.sum;
    C.pre = max(L.pre, L.sum + R.pre);
    C.suf = max(R.suf, R.sum + L.suf);
    C.val = max({L.val, R.val, L.suf + R.pre});
    return C;
}

vector<vector<pl>> seg;
int a[(1<<18) + 5];

void build(int pos, int level, int l, int r){
    int states = 1 << level;
    seg[pos].resize(states);
    if(level == 0){
        seg[pos][0] = pl(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(pos<<1, level-1, l, mid);
    build(pos<<1|1, level-1, mid+1, r);

    const vector<pl> &Lvec = seg[pos<<1];
    const vector<pl> &Rvec = seg[pos<<1|1];
    for(int mask = 0; mask < states; ++mask){
        int sub = mask >> 1;
        int b = mask & 1;
        const pl &A = (b == 0 ? Lvec[sub] : Rvec[sub]);
        const pl &B = (b == 0 ? Rvec[sub] : Lvec[sub]);
        seg[pos][mask] = mergePL(A, B);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    if(!(cin >> n)) return 0;
    int N = 1 << n;
    for(int i = 0; i < N; ++i) cin >> a[i];
    int q; cin >> q;
    vector<int> queries(q);
    for(int i=0;i<q;i++) cin >> queries[i];

    seg.assign(2 * N, vector<pl>());

    build(1, n, 0, N-1);

    int mask = 0;
    for(int k : queries){
        mask ^= (1 << k);
        cout << seg[1][mask].val << '\n';
    }
    return 0;
}
