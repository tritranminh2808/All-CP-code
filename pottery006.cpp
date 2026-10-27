#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,sol=-INT_MAX;
const int p=1e5+5;
int a[p],b[p];
signed main(){
	freopen("pottery006.inp","r",stdin);
	freopen("pottery006.out","w",stdout);
	cin >> t>>n;
	for(int i=0;i<n;i++) cin >> a[i];
	cin >> m;
	for(int i=0;i<m;i++) cin >> b[i];
	sort(a,a+n);sort(b,b+m);
	//if(n>m) swap(a,b);
	for(int i=0;i<n;i++){
		sol=max(sol,min(t/a[i],(t-max(a[i],b[i]))/b[i]));
		//cout << b[i]<< endl;
	}
	cout << sol;
	return 0;
	
}
