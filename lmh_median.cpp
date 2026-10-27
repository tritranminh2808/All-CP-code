#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
using namespace __gnu_pbds;
int a[200005];
vector <int> b;
gp_hash_table<int ,int > mp;
int olv[2000005];
int st[2000005];
void update(int i, int v){
    for(;i<=300000;i+=i&-i) st[i]+=v;
}
int find(int i){
    int s=0;
    for(;i>0;i-=i&-i) s+=st[i];
    return s;
}
void nen(){
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=0;i<b.size();i++) {
        mp[b[i]]=i+1;
        olv[i+1]=b[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int nu,q; cin >> nu >> q;
    int n=2*nu+1;
    for(int i=1;i<=n;i++){
         cin >> a[i];
         b.push_back(a[i]);
    }
    vector <pair <int, int > > Q;
    while(q--){
        int u,v; cin >> u >> v;
        b.push_back(v);
        Q.push_back({u,v});
    }
    nen();
    for(int i=1;i<=n;i++) {
        a[i]=mp[a[i]];
        update(a[i],1);
    }
    for(int i=0;i<Q.size();i++){
        int u=Q[i].first+1,v=mp[Q[i].second];
        update(a[u],-1);
        a[u]=v;
        update(v,1);
        int l=1,r=b.size()+1;
        int sol=0;
        int X=find(300000);
        while(l<=r){
            int mid=(l+r)/2;
            int x=find(mid-1),y=X-find(mid-1);
            if(y-x>0){
                sol=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout << olv[sol] << "\n";
    }
    return 0;
}