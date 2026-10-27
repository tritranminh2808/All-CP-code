#include <bits/stdc++.h>
using namespace std;
vector <int > adj[100005];
struct pl{
    int u,w;
};
const int pp=2e4+5;
struct cmp{
    bool operator()(pl &a,pl &b){
        return a.w>b.w;
    }
};
priority_queue< pl, vector <pl> , cmp> pq;
int kc[pp];
vector <int> kxe[pp];
unordered_set <int> road[pp];
void dijkstra(int z){
    kc[z]=0;
    road[z]={0};
    pq.push({z,0});
    while(!pq.empty()){
        pl p=pq.top();
        pq.pop();
        if(kc[p.u]<p.w) continue;
        for(auto i:adj[p.u]){
            if(p.w+1<kc[i]){
                kc[i]=p.w+1;
                road[i]=road[p.u];
                if(!kxe[i].empty()) {
                    road[i].clear();
                    for(auto j:road[p.u]) {
                        int gg=j;
                        for(auto g:kxe[i]) gg|=(1<<g); 
                        road[i].insert(gg);
                    }
                }
                pq.push({i,kc[i]});
            }
            else if(p.w+1==kc[i]){
                if(!kxe[i].empty()) {
                    for(auto j:road[p.u]){
                        int gg=j;
                        for(auto g:kxe[i]) gg|=(1<<g);
                        road[i].insert(gg);
                    }
                }
                else for(auto j:road[p.u]) road[i].insert(j);
                // pq.push({i, kc[i]});
            }
        }
    }
}
int cnt[pp];
int dp[pp][201];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    // cout << "NGUUUU";
    while(t--){
        int n,m; cin>> n >> m;
        while(!pq.empty()) pq.pop();
        for(int i=1;i<=n;i++){
            kc[i]=INT_MAX;
            adj[i].clear();
            kxe[i].clear();
            cnt[i]=0;
            road[i].clear();
        }
        for(int i=1;i<=m;i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int f,k;
        cin >> f;
        vector <int> a(f+1);
        for(int i=1;i<=f;i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        cin >> k;
        for(int i=1;i<=k;i++){
            int u; cin >> u;
            kxe[a[u]].push_back(i);
        }
        dijkstra(1);
        int cnt=0,sol=0;
        
        
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=f;i++){
            int x=a[i];
            if(!kxe[x].empty()) {
                kxe[x].pop_back();
                continue;
            }
            // cout << x << " ";
            // for(auto kk:road[x]) cout << kk << " ";
            cnt++;
            for(int mask=0;mask<(1<<(k+1));++mask){
                for(auto j: road[a[i]]) dp[cnt][mask|j]|=dp[cnt-1][mask];
            }
        }
        for(int mask=0;mask<(1<<(k+1));mask++) {
            if(dp[cnt][mask]) sol=max(sol,__builtin_popcount(mask));
            // cout << sol << " ";
        }
        cout << k-sol << "\n";
    }
    return 0;
}