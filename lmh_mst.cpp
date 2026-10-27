#include <bits/stdc++.h>
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        sz[i]=1;
        par[i]=i;
    }
    while(m--){
        int x,y,z; cin >> x >> y >> z;
        a.push_back({x,y,z});
    }
    sort(a.begin(),a.end(),cmp);
    long long sol=0;
    for(auto i:a){
        int u=find(i.u),v=find(i.v);
        if(u!=v){
            sol+=i.w;
            add(u,v);
        }
    }
    cout << sol;
    return 0;
}