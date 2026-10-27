#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001],a[100005],b[100005];
int main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	int m; cin >> m;
	for(int i=1;i<=m;i++) cin >> b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	vector <int> chung;
	int i=n,j=m;
	while(i>0&&j>0){
		if(a[i-1]==b[j-1]) {
			chung.push_back(a[i-1])
		}
	}
}
