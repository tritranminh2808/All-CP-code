#include <bits/stdc++.h>
using namespace std;
int dp[100005];
bool check[1000005];
int main(){
	dp[1]=1;
	dp[2]=2;
	int ind=4;
	check[4]=1;
	while(ind<100005){
	//	cout << ind << " ";
		ind=(ind+1)*2;
		check[ind]=1;
	}
	for(int i=3;i<100005;++i){
		if(check[i-1]==1) dp[i]=dp[i-1]+1;
		else dp[i]=dp[i-1];
	//	cout << i << " " << dp[i] << "\n";  
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << dp[n] << "\n";
	}
}
