#include <bits/stdc++.h>
#define int long long
using namespace std;
int c=257;
const int mod=1e9+7;
int hashT[100005],power[100005];
string a;
int n;

signed main(){
	power[0]=1;
	for(int i=1;i<=100000;i++) power[i]=power[i-1]*c%mod;
	cin >> a;
	n=a.length();
	a='!'+a;
	for(int i=1;i<=n;i++)hashT[i]=(hashT[i-1]*c+a[i]+1)%mod;
	int t; cin >> t;
	while(t--){
		int l,r,u,v;
		cin >> l >> r >> u >> v;
		int k=(hashT[r]-hashT[l-1]*power[r-l+1])%mod,k2=(hashT[v]-hashT[u-1]*power[v-u+1])%mod;
		if(k<0) k+=mod;
		if(k2<0) k2+=mod;
		if(k==k2) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}
