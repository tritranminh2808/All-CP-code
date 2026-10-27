#include <bits/stdc++.h>
// #pragma GCC optimize("O2,unroll-loops,inline")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") 
using namespace std;
struct pl{
    int u,v,w;
};
vector <pl> a;
bool cmp(pl x ,pl y){
    return x.w<y.w;
}
int sz[100005];
int par[100005];
int find(int u){
    if(par[u]==u) return u;
    return par[u]=find(par[u]);
}
void add(int u,int v){
    u=find(u);
    v=find(v);
    if(sz[u]<sz[v]){
        par[u]=v;
        sz[v]+=sz[u];
        return;
    }
    par[v]=u;
    sz[u]+=sz[v];
}
bool cmp_pl(const pl &x, const pl &y) {
    return x.w < y.w;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    while(m--){
        int x,y,z; cin >> x >> y >> z;
        vector <pl> b;
        pl e={x,y,z};
        auto it = lower_bound(a.begin(), a.end(), e, cmp_pl);
        a.insert(it, e);
        // a.push_back({x,y,z});
        for(int i=1;i<=n;i++) {
            sz[i]=1;
            par[i]=i;
        }
        // sort(a.begin(),a.end(),cmp);
        long long sol=0;
        int cnt=0;
        for(auto i:a){
            int u=find(i.u),v=find(i.v);
            if(u!=v){
                sol+=i.w;
                cnt++;
                add(u,v);
                b.push_back({i.u,i.v,i.w});
            }
        }
        if(cnt!=n-1) cout << "123456789\n";
        else cout << sol << "\n";
        swap(a,b);
    }
    
    return 0;
}