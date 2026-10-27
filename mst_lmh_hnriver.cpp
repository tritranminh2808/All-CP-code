#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
int n,m;
int kc[100005];
struct pl{
    int u,t,c;
};
struct struc{
    int w,u;
};
struct cmp{
    bool operator()(struc &a, struc &b){
        return a.w>b.w;
    }
};
vector <pl> adj[100005];
priority_queue<struc, vector <struc> , cmp> pq;
int t[100005];
void dijkstra(int u){
    kc[u]=0;
    pq.push({0,u});
    while(!pq.empty()){
        struc p=pq.top();
        pq.pop();
        if(kc[p.u]<p.w) continue;
        for(auto i:adj[p.u]){
            if(p.w>=i.t) {
                if(p.w+i.c<kc[i.u]){
                    kc[i.u]=p.w+i.c;
                    pq.push({kc[i.u],i.u});
                    t[i.u]=p.u;
                }
            }
            else{
                if(p.w+i.c+i.t-p.w<kc[i.u]){
                    kc[i.u]=p.w+i.c+i.t-p.w;
                    pq.push({kc[i.u],i.u,});
                    t[i.u]=p.u;
                }
            }
        }
    }
}
vector <int> trace(int s, int r){
    vector <int> v;
    int cur=r;
    while(1){
        v.push_back(cur);
        if(cur==s) break;
        cur=t[cur];
    }
    reverse(v.begin(),v.end());
    return v;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin >> n >> m;   
    for(int i=0;i<m;i++){
        int x,y,t,c; cin >> x >> y >> t >> c;
        adj[x].push_back({y,t,c});
        adj[y].push_back({x,t,c});
    }
    for(int i=1;i<=n;i++) kc[i]=1e18;
    dijkstra(1);
    cout << kc[n] << "\n";
    for(auto i:trace(1,n)) cout << i << " ";
    return 0;

}