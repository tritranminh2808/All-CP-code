#include <bits/stdc++.h>
using namespace std;
long long dp[10000];
int main(){
	long long n;cin >> n;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		if(i%2==0) dp[i]=dp[i-1]+1;
		else {
			if((i/2)%2==1) dp[i]=dp[i-1]+1;
			else dp[i]=dp[i-1];
		}
	//	cout<< dp[i] < " ";
	}
	cout << dp[n];
	return 0;
}
