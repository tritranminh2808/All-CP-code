#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=108327438374;
int ss=0,l=9999999,r=-9999999;
int sum[1000005],sum2[1000005];
signed main(){
	int n; cin >> n;
	vector <int> v(n+1);
	for(int i=1;i<=n;i++) {
		cin >> v[i];
		l=min(v[i],l);
		r=max(r,v[i]);
		sum[i]=sum[i-1]+v[i];
		sum2[i]=sum2[i-1]+(v[i]*v[i]);	
	}
//	for(int i=1;i<=n;i++) cout << sum2[i] << "\n";
	for(int i=-1000000;i<=1000000;i++){
		int t=sum2[n]+n*i*i-2*sum[n]*i;
	//	cout << i << " " << t << endl;
		sol=min(sol,t);
	}
	cout << sol;
	return 0;
}
