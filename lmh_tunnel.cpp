#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,t;
int sz[1000005],par[1000005];
struct pl{
    int u,v,h,d;
};
vector <pl> canh;

bool cmp(pl a, pl b){
    return a.h>b.h;
}
int cnt[1000005];
int find(int u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(sz[u]>sz[v]){
        par[v]=u;
        sz[u]+=sz[v];
    }
    else{
        par[u]=v;
        sz[v]+=sz[u];
    }
}
vector <pair <int ,int > > adj[200005];
int kc[200005],tt[200005];
priority_queue<pair <int, int > , vector <pair <int, int > > , greater<pair <int, int > > > pq;
void dijkstra(int u){
    kc[u]=0;
    pq.push({0,u});
    while(!pq.empty()){
        pair <int , int >  p=pq.top();
        pq.pop();
        if(kc[p.second]<p.first) continue;
        for(auto i:adj[p.second]){
            if(kc[i.first]>p.first+i.second){
                kc[i.first]=p.first+i.second;
                pq.push({kc[i.first],i.first});
                tt[i.first]=p.second;
            }
        }
    }
}
vector <int> trace(int s, int t){
    int x=t;
    vector <int> ss;
    while(1){
        ss.push_back(x);
        if(x==s) break;
        x=tt[x];
    }
    reverse(ss.begin(),ss.end());
    return ss;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int u,v,h,d; cin >> u >> v >> h >> d;
        canh.push_back({u,v,h,d});
    }
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
    sort(canh.begin(),canh.end(),cmp);
    vector <pl> cmoi;
    int maxx=0;
    for(auto i:canh) {
        int x=i.u,y=i.v;
        // cout << x << " " << y << " " << i.d << "\n";
        x=find(x);
        y=find(y);
        if(x==y) continue;
        add(x,y);
        if(find(s)==find(t)){
            maxx=i.h;
            break;
        }
    }
    for(auto i:canh){
        int x=i.u,y=i.v,w=i.d,h=i.h;
        if(h<maxx) break;
        // cout << x << " " << y << " "<< w << "\n";
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    for(int i=1;i<=n;i++) kc[i]=1e18;
    dijkstra(s);
    vector <int> sol=trace(s,t);
    cout << sol.size() << "\n";
    for(auto i:sol) cout << i << " ";
    return 0;
}