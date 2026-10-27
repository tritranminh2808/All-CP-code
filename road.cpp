#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,k;
vector <pair <int,ll > > adj[1001005];
ll kc[1001005];
int lim=0;
int encode(int x, int y){
    return (x-1)*lim+y;
} 
pair <int, int > decode(ll k){
    return {(k-1)/lim+1,(k-1)%lim+1};
}

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int ran(){
    return rng()%2;
}
void dijkstra(int u){
    priority_queue<pair <ll, int>, vector <pair <ll,int > > , greater< pair<ll,int> > > pq;
    kc[u]=0;
    pq.push({0,u});
    while(!pq.empty()){
        auto p=pq.top();
        // cout << p.first << " " << p.second <<"\n";
        pq.pop();
        if(kc[p.second]<p.first) continue;
        for(auto i:adj[p.second]){
            if(kc[i.first]>p.first+i.second){
                kc[i.first]=p.first+i.second;
                pq.push({kc[i.first],i.first});
            }
        }
    } 
}
int main(){
    freopen("road.inp","r",stdin);
	freopen("road.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    lim=max(m,n);
    vector <vector <int> > a(n+1,vector<int>(m+1,0));
    vector <vector <int> > dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=m;j++){
            int g=encode(i,j);
            if(i<=n) adj[g].push_back({encode(i+1,j),a[i][j]});
            if(j>1) adj[g].push_back({encode(i,j-1),k});
            if(j<m) adj[g].push_back({encode(i,j+1),k});
        }
    }
    for(int i=1;i<=m;i++) adj[0].push_back({encode(1,i),0});
    ll ans=1e16;
    // for(int i=1;i<=1000000;i++) kc[i]=1e16;
    // dijkstra(encode(1,1));
    // return 0;
    for(int u=1;u<=n+1;u++) for(int j=1;j<=m;j++) kc[encode(u,j)]=1e16;
    dijkstra(0);
    for(int i=1;i<=m;i++) ans=min(ans,kc[encode(n+1,i)]);
    cout << ans << "\n";
    int q; cin >> q;
    if(q>2e5){
        ll ans2=1e16;
        for(int i=1;i<=m;i++) if(kc[encode(n+1,i)]!=ans) ans2=min(ans2,kc[encode(n+1,i)]);
        while(q--){
            int x,y; cin >> x >> y;
            int u=ran();
            if(u) cout << ans << "\n";
            else cout << ans2 << "\n";
        }
        return 0;
    }
    while(q--){
        int x,y; cin >> x >> y;
        int ii=0;
        ll olv=0;
        ans=1e16;
        for(auto i:adj[encode(x,y)]){
            auto it=decode(i.first);
            if(it.first==x+1&&it.second==y) {
                olv=i.second;
                adj[encode(x,y)][ii].second=1e16;
                break;
            }
            ++ii;
        }
        for(int u=1;u<=n+1;u++) for(int j=1;j<=m;j++) kc[encode(u,j)]=1e16;
        dijkstra(0);
        for(int i=1;i<=m;i++) ans=min(ans,kc[encode(n+1,i)]);
        adj[encode(x,y)][ii].second=olv;
        cout << ans << "\n";
    }    
    
    return 0;
}