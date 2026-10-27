#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct pl{
	int x,y,w,id;
};
pl edge[200005];
int par[200005],sz[200005];
int find(int x){
	if(par[x]==x) return x;
	par[x]=find(par[x]);
	return par[x];
}
void add(int x, int y){
	x=find(x);y=find(y);
	if(x==y) return;
	if(sz[x]>sz[y]){
		par[y]=x;
		sz[x]+=sz[y];
		return;
	}
	par[x]=y;
	sz[y]+=sz[x];
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		par[i]=i;
		sz[i]=1;
	}
	vector <pair <int, int > > a;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        a.push_back({u,v});
    }
    vector <string> sol;
    for(int i=m-1;i>=0;i--){
        int u=a[i].first,v=a[i].second;
        if(find(u)!=find(v)) sol.push_back("NO\n");
        else sol.push_back("YES\n");
        add(u,v);
    }
    for(int i=m-1;i>=0;i--) cout << sol[i];
	return 0;
}
