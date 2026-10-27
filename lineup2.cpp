#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int sol=1;
int l[1000005],a[1000005],dp[1000005],pre[10000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	stack<int> st;
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
		if(st.empty()) l[i]=n+1;
		else l[i]=st.top();
		st.push(i);
	}
	dp[n+1]=1;
	pre[n+1]=1;
	for(int i=n;i>=1;--i){
		if(l[i]-i>1) dp[i]=(dp[i]+pre[i+1]-pre[l[i]+1]+mod)%mod;
		else dp[i]=dp[i+1]%mod;
		pre[i]=(pre[i+1]+dp[i]+mod)%mod;
		dp[i]%=mod;
//		cout << dp[i] << " ";
	}
	cout << dp[1]%mod;
//	for(int i=1;i<=n;i++) cout << l[i] << " ";
}
