#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int sol=-1;
int a[p],dp[p];
int k,n;
int main(){
	 cin >> k >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
//	cout << a[1];
	dp[1]=1;int c=1;
	for(int i=2;i<=k;i++){
		if(c<=n&&i==a[c]){
			dp[i]=0;
			c++;
		}else{
			dp[i]=(dp[i-2]+dp[i-1])%14062008;
		}
	}
	cout << dp[k];
	return 0;
}
