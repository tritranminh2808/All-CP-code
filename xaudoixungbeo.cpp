#include <bits/stdc++.h>
#define int long long
using namespace std;
int c=31;
const int mod=1e9+7;
int hash1[100005], hash2[100005],power[1000005];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	power[0]=1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	int n; cin >> n;
	string a;
	cin >> a;
	a=' '+a+' ';
	for(int i=1;i<=n;i++) 
	{
		hash1[i]=(hash1[i-1]*c+a[i]-'a'+1)%mod;
	
//		cout<< hash1[i] << endl;	
	}
	reverse(a.begin(),a.end());
	for(int i=1;i<=n;i++) hash2[i]=(hash2[i-1]*c+a[i]-'a'+1)%mod;
	int q;cin >> q;
//	cout << hash1[5] - hash1[1] * power[4]  << '\n' << hash1[5]- hash1[2] * power[3] << endl;
	while(q--){
		int l,r; cin >> l >> r;
		int r2=n-l+1,l2=n-r+1;
		long long memaybeo=(hash1[r]-hash1[l-1]*power[r-l+1])%mod,bomaygay=(hash2[r2]-hash2[l2-1]*power[r2-l2+1])%mod;
		if(memaybeo<0) memaybeo+=mod;
		if(bomaygay<0) bomaygay+=mod;
//		cout << bomaygay << " " << memaybeo << "\n";
		if(bomaygay==memaybeo) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
