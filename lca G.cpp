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
void buildA(){
	for(int i=1;i<=17;i++){
		for(int j=1;j<=n;j++) jumpA[i][j]=jumpA[i-1][jumpA[i-1][j]];
	}
}
void buildB(){
	for(int i=1;i<=17;i++){
		for(int j=1;j<=n;j++) jumpB[i][j]=jumpB[i-1][jumpB[i-1][j]];
	}
}
int nhayA(int u, int dist){
	for(int i=17;i>=0;i--){
		if(dist>=(1<<i)){
			dist-=(1<<i);
			u=jumpA[i][u];
		}
	}
	return u;
}
int nhayB(int u, int dist){
	for(int i=17;i>=0;i--){
		if(dist>=(1<<i)){
			dist-=(1<<i);
			u=jumpB[i][u];
		}
	}
	return u;
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
	buildA();
	maxx=-1;
	for(int i=1;i<=n;i++){
		if(depB[i]>maxx){
			maxx=depB[i];
			B=i;
		}
	}
	memset(depB,0,sizeof(depB));
	dfsB(B,0);
	buildB();
//	for(int i=1;i<=n;i++) cout << depB[i] << " ";

	cin >> q;
	while(q--){
		int u,d; cin>> u >> d;
		if(depA[u]>depB[u]){
			if(depA[u]<d) cout << "-1\n";
			else cout << nhayA(u,d) << "\n";
		}
		else{
			if(depB[u]<d) cout << "-1\n";
			else cout << nhayB(u,d) << "\n";
		}
	}
	return 0;
}
