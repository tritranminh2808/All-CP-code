#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[4005],pre[4005];
int mp[360000];
int sol=0;
signed main(){
	int k,n; cin >> k >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		pre[i]=pre[i-1]+a[i];
	}
	if(k<0){
		cout << 0;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) mp[pre[j]-pre[i-1]]++;
	}
	if(k==0){
		cout << mp[0]*n*(n+1)-mp[0]*mp[0];
		return 0;
	}
	for(int j=1;j<sqrt(k);j++){
		if(k%j==0){
			if(j<=36000&&k/j<=36000) sol+=2*mp[j]*mp[k/j];
		}
	}
	int x=sqrt(k);
	if(x*x==k){
		sol+=mp[x]*mp[x];
	}
	cout << sol;
	return 0;
}
