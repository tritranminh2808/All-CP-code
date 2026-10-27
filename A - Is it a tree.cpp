#include <bits/stdc++.h>
using namespace std;
int m,n;
const int p=1e5+5;
bool check[p];
vector < vector < int > > vt(p);
void dfs(int u){
	check[u]=1;
	for(auto i : vt[u]){
		if(check[i]==1) continue;
		dfs(i);
	}
}
int main(){
	cin >> n >> m;
	if(n!=m+1) {
		cout << "NO";return 0;
	}
	
	for(int i=0;i<n-1;++i){
		int u,v; 
		cin >> u >> v;

		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		if(check[i]==0){
			cout << "NO";return 0;
		}
	}
	cout << "YES";
	return 0;
}
