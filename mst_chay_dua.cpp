#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e6+5,mod=1e9+7;
int par[p];
int sz[p];
int power[100005];
int find(int u){
	if(par[u]==u) return u;
	return par[u]=find(par[u]);
}
void add(int u, int v){
	u=find(u);v=find(v);
	if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
}
int n,m;
struct pl{
	int a,b,w;
};
vector <pl> canh;
int sol=0;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    power[0]=1;
    for(int i=1;i<=100005;i++) power[i]=power[i-1]*3%mod;
	cin >> n >> m;
    for(int i=0;i<=n+1;i++){ sz[i]=1;par[i]=i;}
	for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        canh.push_back({u,v,power[i]});
    }
    reverse(canh.begin(),canh.end());
    for(auto i:canh){
        int x=i.a,y=i.b;
        x=find(x);
        y=find(y);
        if(x==y) continue;
        if((find(0)==x&&find(n-1)==y)||(find(0)==y&&find(n-1)==x)) sol=(sol+i.w)%mod;
        else add(x,y);
    }
    cout << sol;
	return 0;
}
