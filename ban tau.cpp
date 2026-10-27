#include <bits/stdc++.h>
using namespace std;
struct pl{
	int val,r;
};
int dp[505][505];
int a[505];
int n,k;
int st[15][10005];
void build(){
	for(int i=1;i<=n;i++) st[0][i]=a[i];
	for(int i=1;i<=14;i++){
		for(int j=1;j+(1<<i)-1<=n;j++) st[i][j]=max(st[i-1][j],st[i-1][j+(1<<i-1)]);
	}
}
int find(int l, int r){
	int k=__lg(r-l+1);
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
int pre[100005];
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	build();
	for(int i=1;i<=n;i++) dp[0][i]=find(1,i)*i-pre[i];
//	for(int i=1;i<=n;i++) cout << dp[0][i] << " ";
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j];
			for(int p=1;p<=j;p++) {
				dp[i][j]=min(dp[i][j],dp[i-1][p-1]+find(p,j)*(j-p+1)-pre[j]+pre[p-1]);
//				cout << j << " " << p << ":"<< dp[i][j] << "\n";
			}
		}
	}
	int sol=INT_MAX;
	for(int i=1;i<=k;i++) sol=min(sol,dp[i][n]);
	cout << sol;
	return 0;
}
