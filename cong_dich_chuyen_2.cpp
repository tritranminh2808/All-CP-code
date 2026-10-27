#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int adj[200005];
int par[200005],sz[200005],in[200005];
int find(int u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
}
int lap[200005],comp[200005],pos[200005],len[200005],root[200005],dis[200005];
vector<int> sech[200005];
int up[30][200005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
        lap[i]=1;
        dis[i]=-1;
    }
	for(int i=1;i<=n;i++){
		int u; cin >> u;
        in[u]++;
        // add(u,i);
        adj[i]=u;
        sech[u].push_back(i);
	}
    queue <int> q;
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    while(!q.empty()){
        int p=q.front();
        q.pop();
        lap[p]=0;
        if(!--in[adj[p]]) q.push(adj[p]);
    }
    int id=0;
    for(int i=1;i<=n;i++){
        if(!lap[i]||comp[i]>0) continue;
        id++;
        int cur=i,p=0;
        //dfs
        do{
            comp[cur]=id;
            pos[cur]=p++;
            cur=adj[cur];
        }while(cur!=i);
        len[id]=p;
    }
    queue<int> qq;
    for(int i=1;i<=n;i++) {
        if(lap[i]){
            root[i]=i;
            dis[i]=0;
            qq.push(i);
        }
    }
    while(!qq.empty()){
        int p=qq.front();
        qq.pop();
        for(auto i:sech[p]){
            if(lap[i]||dis[i]>-1) continue;
            dis[i]=dis[p]+1;
            root[i]=root[p];
            comp[i]=comp[p];
            qq.push(i);
        }
    }
    for(int i=1;i<=n;i++) up[0][i]=adj[i];
    for(int k=1;k<21;k++) for(int i=1;i<=n;i++) up[k][i]=up[k-1][ up[k-1][i] ];
    while(m--){
        int u,v; cin >> u >> v;
        if(comp[u]!=comp[v]) {
            cout << "-1\n";
            continue;
        }
        if(lap[u]&&lap[v]){
            int ln=len[comp[u]];
            int ans=(pos[v]-pos[u]+ln)%ln;
            cout << ans << "\n";
            continue;
        }
        if(!lap[u]&&!lap[v]){
            int d=dis[u]-dis[v];
            if(d<0) {
                cout << "-1\n";
                continue;
            }
            int cur=u;
            for(int k=0;k<21;k++) if((d>>k)&1) cur = up[k][cur];
            if(cur==v) cout<< (dis[u]-dis[v]) <<"\n"; 
            else cout<<"-1\n";
            continue;
            // continue;
        }
        if(!lap[u]&&lap[v]){
            int ln=len[comp[u]];
            int ans=dis[u]+(pos[v]-pos[root[u]]+ln)%ln;
            cout << ans << "\n";
            continue;
        }
        cout << "-1\n";
    }
	return 0;
}
