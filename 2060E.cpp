#include <bits/stdc++.h>
using namespace std;
const int pp=2e5+5;
int n;
int parf[pp],parg[pp],szf[pp],szg[pp],deg[pp];
vector <int> unt[pp];
set<int> adj[pp];
int findf(int u){
    if(parf[u]==u) return u;
    return parf[u]=findf(parf[u]);
}
int findg(int u){
    if(parg[u]==u) return u;
    return parg[u]=findf(parg[u]);
}
void addf(int u, int v){
    u=findf(u);
    v=findf(v);
    if(u==v) return;
    if(szf[u]<szf[v]) swap(u,v);
    for(auto i:unt[v]) unt[u].push_back(i);
    unt[v].clear();
    szf[u]+=szf[v];
    parf[v]=u;
}
void addg(int u, int v){
    u=findg(u);
    v=findg(v);
    if(u==v) return;
    if(szg[u]<szg[v]) swap(u,v);
    szg[u]+=szg[v];
    parg[v]=u;
}
void cok(){
    cin >> n;
    for(int i=1;i<=n;i++){
        parf[i]=i;
        parg[i]=i;
        szf[i]=1;
        szg[i]=1;
        unt[i].clear();
        unt[i].push_back(i);
        adj[i].clear();
    }
    int m1,m2; cin >> m1 >> m2;
    for(int i=0;i<m1;i++){
        int u,v; cin >> u >> v;
        
        addf(u,v);
    }
    for(int i=0;i<m2;i++){
        int u,v; cin >>  u >> v;
        addg(u,v);
    }
    vector <int> lit;
    for(int i=1;i<=n;i++) lit.push_back(findf(i));
    sort(lit.begin(),lit.end());
    lit.erase(unique(lit.begin(),lit.end()),lit.end());
    for(auto p: lit){
        map <int, int > mp;
        for(auto i:unt[p]) mp[findg(i)]++;
        if(mp.size()==1) continue;
        auto it=*mp.rbegin();

    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cok();
    }
    return 0;
}