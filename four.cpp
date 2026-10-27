#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2006],X[4000006];
int sol=0;
const int mod=2e6;
signed  main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++) sol+=X[mod-a[i]-a[j]];
		for(int j=1;j<i;j++) X[mod+a[i]+a[j]]++;
	}
	cout << sol;
	return 0;
}
