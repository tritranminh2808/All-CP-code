#include <bits/stdc++.h>
#define int long long
using namespace std;
struct pl{
    long long sum,pre,suf,val;
    pl(): sum(0), pre(LLONG_MIN/4), suf(LLONG_MIN/4),val(LLONG_MIN/4) {}
    pl (long long x): sum(x), pre(max(0LL, x)), suf(max(0LL, x)), val(max(0LL, x)) {}
};
// pl st[4*(1<<18)+5];
int a[(1<<18)+5];
int dao(int x, int n){
    int r=0;
    for(int i=0;i<n;i++) if((x>>i)&1) r|=(1<<(n-i-1));
    return r;
}

pl merge(pl a, pl b){
    pl c;
    c.sum=a.sum+b.sum;
    c.pre=max(a.pre,a.sum+b.pre);
    c.suf=max(b.suf,b.sum+a.suf);
    c.val=max({a.val,b.val,a.suf+b.pre});
    return c;
}
vector<vector<pl>> seg; 
// vector<long long> a;

void build(int id, int dep, int l, int r){
    int p = 1 << dep;
    seg[id].resize(p);
    if(dep==0){
        seg[id][0]=pl(a[l]);
        return;
    }
    int mid = (l + r)/2;
    build(id*2, dep-1, l, mid);
    build(id*2+1, dep-1, mid+1, r);
    int childp = 1 << (dep-1);
    for(int mask = 0; mask < p; ++mask){
        int sub = mask >> 1;     
        int b = mask & 1;       
        const pl &A=b == 0 ? seg[id<<1][sub] : seg[id<<1|1][sub];
        const pl &B = (b == 0 ? seg[id<<1|1][sub] : seg[id<<1][sub]);
        seg[id][mask]=merge(A,B);
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<(1<<n);i++) cin >> a[i];
    int q; cin >> q;
    vector<int> query(q);
    for(int i=0;i<q;i++) cin >> query[i];
    seg.assign(2*(1<<n),vector<pl>());
    build(1, n, 0,(1<<n)-1);

    int mask = 0;
    for(int k : query){
        mask ^= (1 << k);
       int mask2 =dao(mask, n);
        cout << seg[1][mask2].val << '\n';
    }
    return 0;
}