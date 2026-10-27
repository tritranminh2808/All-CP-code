#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int dp[1000005];
signed main(){
	int n,k; cin >> n >> k;
	vector <int> a(k);
	for(int i=0;i<k;i++) cin >> a[i];
	sort(a.begin(),a.end());
	dp[1]=1;
	for(int i=1;i<=n;i++){
		for(auto j : a){
			if(j>i) break;
			dp[i]+=dp[i-j];
			dp[i]%=mod;
		}
	}
	cout << dp[n]%mod;
}
