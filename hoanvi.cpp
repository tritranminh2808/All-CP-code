#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=8127382121;
signed main(){
	int n,k; cin >> n>>k;
	vector <int> a(n+1);
	int vt=0;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i]==1) vt=i; 
	}
	for(int x=max((int)1,vt-k+1);x<=min(n,vt+k-1);x++){
		int sech=0;
		sech+=(n-x)/(k-1);
		sech+=(x-1)/(k-1);
		if((n-x)%(k-1)!=0) sech++;
		if((x-1)%(k-1)!=0)sech++;
		sol=min(sol,sech);
	}
	cout<< sol;
	return 0;
}
