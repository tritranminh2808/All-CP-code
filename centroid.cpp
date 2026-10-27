#include <bits/stdc++.h>
using namespace std;
vector <int> child[100005];
int dep[100005],sol[100005];
void deep(int u){
	dep[u]=1;
	for(auto i : child[u]){
		deep(i);
		dep[u]+=dep[i];
	}
}
vector <int> hld;
void cook(){
	int j=0;
	for(int i=0;i<hld.size();i++){
		while(j<hld.size()&&dep[hld[j]]*2>dep[hld[i]]) ++j;
		sol[hld[i]]=hld[j-1];
	}
	hld.clear();
}
void cook_hld(int u){
	hld.push_back(u);
	if(child[u].empty()){
		cook();
		return;
	}
	int mxnode=0,mxdep=-INT_MAX;
	for(auto i : child[u]){
		if(dep[i]>mxdep){
			mxdep=dep[i];
			mxnode=i;
		}
	}
	cook_hld(mxnode);
	for(auto i : child[u]){
		if(i!=mxnode) cook_hld(i);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>> n;
	for(int i=2;i<=n;i++){
		int a; cin >> a;
		child[a].push_back(i);
	}
	deep(1);
	cook_hld(1);
	for(int i=1;i<=n;i++) cout << sol[i] << "\n";
	return 0;
}
