#include <bits/stdc++.h>
#define int long long
using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long ran(int l, int r){
    return l+rng()%(r-l+1);
}
unordered_map<int, long long > newv;
unordered_map<long long,bool> se;
long long a[200005];
long long sump[200005],xorp[200005],pres[200005],prex[200005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin >> n >> q;
    for(int i=1;i<=200000;i++){
        long long cc=ran(-1e13,1e13);
        while(se[cc]==1)    cc=ran(-1e13,1e13);
        newv[i]=cc;
        se[cc]=1;
    }
    
    for(int i=1;i<=n;i++){
        int u=newv[i];
        // cout << u << " ";
        sump[i]=sump[i-1]+u;
        xorp[i]=xorp[i-1]^u;
    }
    for(int i=1;i<=n;++i){
        cin >> a[i];
        a[i]=newv[a[i]];
    }
    // cout << 0;
    for(int i=1;i<=n;i++){
        pres[i]=pres[i-1]+a[i];
        prex[i]=prex[i-1]^a[i];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        if(sump[r-l+1]==pres[r]-pres[l-1]&&xorp[r-l+1]==prex[r]^prex[l-1]) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}