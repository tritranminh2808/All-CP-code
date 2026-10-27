#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n,m,q   ;
vector <int> adj[500005];

vector <int> euler;
int stt[500005],ed[500005],dep[500005];
int timer=0;
map<pair<int, int > ,int> mp;
void dfs(int u,int v){
    stt[u]=++timer;
    for(auto i:adj[u]){
        if(i==v) continue;
        dep[i]=dep[u]+1;
        dfs(i,u);
    }
    ed[u]=timer;
}
void build(int u,int v){

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=2;i<=n;i++){
        int u; cin >> u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    dfs(1,0);
    string s; cin >> s;
    s='!'+s;
    build(1,0);
    while(q--){

    }
}