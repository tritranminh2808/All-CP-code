#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
vector <int> adj[200005];
int depB[200005],depA[200005],jumpA[18][200005],jumpB[18][200005];
void dfsA(int u,int v){
	for(auto i:adj[u]){
		if(i==v) continue;
		depA[i]=depA[u]+1;
		jumpA[0][i]=u;
		dfsA(i,u);
	}
}
void dfsB(int u,int v){
	for(auto i:adj[u]){
		if(i==v) continue;
		depB[i]=depB[u]+1;
		jumpB[0][i]=u;
		dfsB(i,u);
	}
}
int A,B;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<n;i++){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfsA(1,0);
	int maxx=-1;
	for(int i=1;i<=n;i++){
		if(depA[i]>maxx){
			maxx=depA[i];
			A=i;
		}
	}
	memset(depA,0,sizeof(depA));
	dfsB(A,0);
	dfsA(A,0);
	maxx=-1;
	for(int i=1;i<=n;i++){
		if(depB[i]>maxx){
			maxx=depB[i];
			B=i;
		}
	}
	memset(depB,0,sizeof(depB));
	dfsB(B,0);
//	for(int i=1;i<=n;i++) cout << depB[i] << " ";
	for(int i=1;i<=n;i++){
		if(depA[i]>depB[i]) cout << depA[i] << " ";
		else cout << depB[i] << " ";
	}
	
	return 0;
}
