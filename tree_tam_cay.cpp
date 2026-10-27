#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> adj[100005];
int sol=0;
int dep[100005],dep2[100005];
void dfs(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dep[i]=dep[u]+1;
        dfs(i,u);
    }
}
void dfs2(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dep2[i]=dep2[u]+1;
        dfs2(i,u);
    }
}
int A,B;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int cur=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>cur){
            cur=dep[i];
            A=i;
        }
    }
    for(int i=1;i<=n;i++) dep[i]=0;
    dfs(A,0);
    cur=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>cur){
            cur=dep[i];
            B=i;
        }
    }
    dfs2(B,0);
    int minn=INT_MAX;
    for(int i=1;i<=n;i++){
        int kc=max(dep[i],dep2[i]);
        minn=min(minn,kc);
    }
    vector <int> sol;
    for(int i=1;i<=n;i++){
        int kc=max(dep[i],dep2[i]);
        if(kc==minn) sol.push_back(i);
    }
    cout << sol.size() << "\n";
    for(auto i:sol) cout <<i << " ";
    return 0;
}
