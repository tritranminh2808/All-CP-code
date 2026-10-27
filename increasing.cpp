#include <bits/stdc++.h>
using namespace std;
int n,k; 
vector <int> v(2000005);
int sol=1e9;
int zuli(int a){
	int in=1;
	int s=0;
	for(int i=a;i<=a+k-1;++i){
		if(v[i]>in) return 1e9;
		s+=in-v[i];
		in++;
	}
	return s;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> v[i];
	for(int i=1;i<=n-k+1;i++) if(v[i]<=1) sol=min(sol,zuli(i));
	if(sol==1e9) cout << -1;
	else cout << sol;
	return 0;
}
