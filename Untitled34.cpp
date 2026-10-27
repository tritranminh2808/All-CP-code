#include <bits/stdc++.h>
using namespace std;
const int p=1e6+1;
int sum[p],last[p],dp[p],a[p];
const int mod=123456789;
int main() {
	dp[0]=1;
    long long n; cin >> n; 
    for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		dp[i] = (dp[i - 1] * 2)%mod;
    	if (last[a[i]] > 0) dp[i] = (dp[i] - dp[last[a[i]] - 1]+mod)%mod;
    	last[a[i]] = i;
	}cout << dp[n]%mod;
    return 0;
}

