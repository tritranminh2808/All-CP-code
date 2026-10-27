#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int >  adj[100005];
int field[100005],f[100005],d[100005];
int st[100005];
void update(int i, int v){
    for(;i<=n;i+=i&-i) st[i]+=v;
}
int find(int i){
    int s=0;
    for(;i>0;i-=i&-i) s+=st[i];
    return s;
}
void dfs(int u,int v){
    update(field[u],1);
    for(auto i:adj[u]){
        if(i==v) continue;
        f[i]=find(field[i]);
        dfs(i,u);
    }
    update(field[u],-1);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>> n;
    m=n-1;
    while(m--){
        int a,b; cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        int u; cin >> u;
        field[u]=i;
        d[i]=u;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout << f[d[i]]<< "\n";
    return 0;
}