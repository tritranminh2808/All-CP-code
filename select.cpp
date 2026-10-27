#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e6+5;
int par[p],ss[p];
vector <int> sz(p,1);
int find(int u){
	if(par[u]==u) return u;
	else {
		par[u]=find(par[u]);
		return par[u];
	}
}
int cnt=0;
void add(int u, int v){
	u=find(u);v=find(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
    ss[u]+=ss[v];
}
int n,m,q;
vector <int> adj[200005];
bool check[200005];
int w[2000005];
struct pl{
	int typ,l,r;
};
pl qq[200005];
vector <int> val[200005];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m >> q;
    set<int> lst;
	for(int i=1;i<=n;i++) {
		par[i]=i;
		cin >> w[i];
        val[i].push_back(w[i]);
        ss[i]=w[i];
	}
    vector <pair <int, int > > edge(m+1);
	for(int i=1;i<=m;i++){
        lst.insert(i);
		int u,v; cin>> u >> v;
		adj[u].push_back(v);
        adj[v].push_back(u);
        edge[i]={u,v};
	}
    for(int i=1;i<=q;i++){
		char c; cin >> c;
		if(c=='D'){
			qq[i].typ=1;
			cin>> qq[i].l;
            lst.erase(qq[i].l);
            check[qq[i].l]=1;
		}
		else{
			qq[i].typ=2;
			cin >> qq[i].l >> qq[i].r;
            val[qq[i].l].push_back(qq[i].r);
            ss[qq[i].l]=qq[i].r;
		}
	}
    multiset<int> st;
	for(auto i:lst)    add(edge[i].first,edge[i].second);
    for(int i=1;i<=n;i++) if(find(i)==i) st.insert(ss[i]);
    // for(auto i:st) cout << i << " ";return 0;
    vector <int> ans(q+1);
    for(int i=q;i>=1;i--){
        ans[i]=*st.rbegin();
        if(qq[i].typ==1){
            int u=edge[qq[i].l].first,v=edge[qq[i].l].second;
            u=find(u);
            v=find(v);
            if(u==v) continue;
            st.erase(st.find(ss[u]));
            st.erase(st.find(ss[v]));
            add(u,v);
            st.insert(ss[find(u)]);
        }
        else{
            int u=qq[i].l;u=find(u);
            st.erase(st.find(ss[u]));
            int preval=val[qq[i].l].back();
            val[qq[i].l].pop_back();
            int nxtval=val[qq[i].l].back();
            ss[u]+=nxtval-preval;
            st.insert(ss[u]);
        }
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
	return 0;
}
