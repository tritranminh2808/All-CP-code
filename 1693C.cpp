#include <bits/stdc++.h>
using namespace std;
vector <int> adj[200005];
int kc[200005];// so ngay toi thieu di tu 1 den i
int cnt[200005];
void dijkstra(int u){
    priority_queue<pair <int, int > , vector<pair <int,int > > , greater<pair <int, int > > > pq;
    kc[u]=0;
    pq.push({kc[u],u});
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        // cout << p.first << " " << p.second << "\n";
        if(kc[p.second]<p.first) continue;
        // int cnt=adj[p.second].size();
        for(auto i:adj[p.second]){
            if(p.first+cnt[i]<kc[i]){
                kc[i]=p.first+cnt[i];
                pq.push({kc[i],i});
            }
            cnt[i]--;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>> n>> m;
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        adj[v].push_back(u);
        cnt[u]++;
        // adj[v].push_back(u);
    }
    // for(int i=1;i<=n;i++) cout << cnt[i] << " ";
    // return 0;
    for(int i=1;i<=n;++i) kc[i]=INT_MAX;
    dijkstra(n);
    // return 0;
    cout << kc[1];
    return 0;
}