#include <bits/stdc++.h>
#define int long long
using namespace std;
int c=257;
const int mod=1e9+7;
int hash1[1000005], hash2[1000005],power[1000005];
string a;
int n;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	power[0]=1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	cin >> a;
	n=a.length();
	a=' '+a;
//	if(check(14,22)) cout << "x";
	for(int i=1;i<=n;i++) hash1[i]=(hash1[i-1]*c+a[i]+1)%mod;
	set<int> st;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int k=(hash1[j]-hash1[i-1]*power[-i+1])%mod;
			if(k<0) k+=mod;
			st.insert(k);
		}
	}
	cout << st.size()+n;
	return 0;
}
