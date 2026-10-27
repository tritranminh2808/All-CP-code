#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int par[p];
vector <vector<int> > d;
vector <bool> check [p];
int dfs(int u,int dem,int re){
	check[u]=1;
	re=max(re,dem);
	dem++;
	for(auto i : vt[u]){
		if(check[i]==1) {
			dem--;
			continue;
		}
		dfs(i,dem,re);
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) par[i]=i;
	for(int i=0;i<m;i++){
		int a,b;cin >> a >> b;
		d[a].push_back(b);
	}	
	int sol=-1;
	for(int i=1;i<=n;i++){
		sol=max(sol,dps(i,1,0));
		check.clear();
	}
}
