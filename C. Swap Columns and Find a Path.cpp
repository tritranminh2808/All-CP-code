#include <bits/stdc++.h>
using namespace std;
int a[2][1000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i=0;i<n;i++){
			a[0][i]=0;
			a[1][i]=0;
		}
		int sol=0;
		for(int i=0;i<2;++i){
			for (int j=0;j<n;j++) cin >> a[i][j];
		}
		vector <pair <int, int > > v;
		for(int i=0;i<n;i++) v.push_back({a[0][i],a[1][i]});
		//v.push_back({a[0][maxind],a[1][maxind]});
		//if(n>1)v.push_back({a[0][maxind2],a[1][maxind2]});
		for(auto i : v) sol+=max(i.first,i.second);
		int res=sol;
		for(auto i : v) sol=max(sol,res+min(i.second,i.first));
		if(sol==res){
			int tru=-99999999;
			for(auto i : v) tru=max(tru,min(i.first,i.second));
			cout << sol+tru << "\n";
		}
		else cout << sol << "\n";
	}
	return 0;
}
