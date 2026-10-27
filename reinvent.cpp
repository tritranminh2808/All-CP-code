#include <bits/stdc++.h>
using namespace std;
vector <int> con[100005];
int a[100005],dep[100005],par[100005];
int sol=INT_MAX;
queue<int> q;
void bfs(){
	while(!q.empty()){
		if(sol<=1){
			cout << sol;
			return;
		}
		int u=q.front();
		q.pop();
		for(auto i:con[u]){
			if(par[i]==0){
				par[i]=par[u];
				dep[i]=dep[u]+1;
				q.push(i);
			}
			else if(par[i]!=par[u]) sol=min(sol,dep[i]+dep[u]+1);
		}
	}
	cout << sol;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,x; cin >> n >> m >> x;
	while(m--){
		int l,r; cin >> l >> r;
		con[l].push_back(r);
		con[r].push_back(l);
	}
	
	for(int i=1;i<=x;i++) {
		cin >> a[i];
		par[a[i]]=a[i];
		q.push(a[i]);
	}
	bfs();
}
