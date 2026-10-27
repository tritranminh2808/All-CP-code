#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> chi[1000000];
int s[1000000],cen[1000000];
void dfs(int u){
	s[u]=1;
	for(auto i : chi[u]){
		dfs(i);
		s[u]+=s[i];
	}
}
vector <int> v;
void xu_li(){
	int k=v.size();int j=0;
	for(int i=0;i<k;i++){
		while(j<k&&s[v[j]]*2>s[v[i]])++j;
		cen[v[i]]=v[j-1];
	}
	v.clear();
}
void hld(int u){
	v.push_back(u);
	if(chi[u].empty()) {
		xu_li();
		return ;
	}
	int m,m2=-1111111111111;
	for (auto i : chi[u]){
		if(s[i]>m2) {
			m=i;
			m2=s[i];
		}
	}
	hld(m);
	for(auto v: chi[u]){
		if(v!=m) hld(v);
	}
}
signed main(){
	int n;cin >> n;
	for(int i=2;i<=n;i++){
		int k; cin >> k;
		chi[k].push_back(i);
		//par[i]=k;
	}
	dfs(1);
	hld(1);
	for(int i=1;i<=n;i++){
		cout << cen[i] << "\n";
	}
	return 0;
}
