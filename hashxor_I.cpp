#include <bits/stdc++.h>
#define int long long
using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long ran(int l, int r){
    return l+rng()%(r-l+1);
}
unordered_map<int, long long > newv;
unordered_map<long long,bool> se;
long long a[100005],b[100005];
long long presa[100005],prexa[100005],presb[100005],prexb[100005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin >> n;
    for(int i=1;i<=100000;i++){
        long long cc=ran(-1e13,1e13);
        while(se[cc]==1)    cc=ran(-1e13,1e13);
        newv[i]=cc;
        se[cc]=1;
    }
    vector <int> c;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        c.push_back(a[i]);
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(int i=1;i<=n;i++) {
        a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin()+1;
        a[i]=newv[a[i]];
        presa[i]=presa[i-1]+a[i];
        prexa[i]=prexa[i-1]^a[i];
    }
    for(int i=1;i<=n;i++) {
        b[i]=lower_bound(c.begin(),c.end(),b[i])-c.begin()+1;
        b[i]=newv[b[i]];
        presb[i]=presb[i-1]+b[i];
        prexb[i]=prexb[i-1]^b[i];
    }
    cin >> q;
    while(q--){
        int l,r,u,v; cin >> l >> r >> u >> v;
        if(l-r!=u-v) {
            cout << "No\n";
            continue;
        }
        if(presa[r]-presa[l-1]==presb[v]-presb[u-1]&&prexa[r]^prexa[l-1]==prexb[v]^prexb[u-1]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}