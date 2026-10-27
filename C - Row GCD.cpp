#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=3e5+5;
int st[21][p],st2[21][p];
int a[p],y[p];
int n,m;
int gcd(int a, int b){
	if(b==0) return abs(a);
	return gcd(b,a%b);
}
int sol,t;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	for(int i=1;i<=n;i++) cin >> a[i];
	int d=0;
	for(int i=1;i<=n;i++) d=gcd(d,a[i]-a[1]);
	for(int i=1;i<=m;i++) {
		cin >> y[i];
		cout << gcd(y[i]+a[1],d) << ' ';
	}
	
	return 0;
}
