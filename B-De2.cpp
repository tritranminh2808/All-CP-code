#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n,m;
set <int> adj[100005];

vector <int> euler;
int pos[100005];
int timer=0;
void dfs(int u,int v){
    pos[u]=++timer;
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
    }
}
bool cmp(int a, int b){
    return pos[a]<pos[b];
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    m=n-1;
    for(int i=1;i<=m;i++){
        int u,v; 
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs(1,0);
    vector <int >v;
    for(int i=1;i<=n;++i) if(adj[i].size()==1) v.push_back(i);
    sort(v.begin(),v.end(),cmp);
    // for(auto i:v) cout << i << " ";
    vector <pair <int , int > > sol;
    int kc=(v.size()+1)/2;
    for(int i=0;i<v.size()-kc;i++) sol.push_back({v[i],v[i+kc]});
    if(v.size()%2==1) sol.push_back({v[(v.size()+1)/2-1],v[0]});
    cout << sol.size() << "\n";
    for(auto i:sol) cout << i.first << " " << i.second << "\n";
}