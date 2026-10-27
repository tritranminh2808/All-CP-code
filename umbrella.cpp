#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100000],b[100000],c[100000],dp[100000];
int n,m;
signed main(){
	cin >> n >>m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int j=1;j<=m;j++) cin >> b[j];
	sort(a+1,a+1+n);
	c[m+1]=INT_MAX;
	//for(int i=0;i<=10000;i++) dp[i]=INT_MAX;
	for(int i=m;i>=1;i--) c[i]=min(c[i+1],b[i]);
	for(int i=1;i<=n;i++){
		int m=INT_MAX;
		for(int j=1;j<=i;j++){
			m=min(dp[j-1]+c[a[i]-a[j]+1],m);
		}
		dp[i]=m;
	}
	cout << dp[n];
}
