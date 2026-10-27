#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1001][1001], dp[1001][1001];
pair <int, int> trace[1001][1001];
int sol=-1e18;
signed main(){
	freopen("board.inp","r",stdin);
	freopen("board.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n >> m;	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int i=1;i<=n;i++) dp[i][1]=a[i][1];
	for(int j=2;j<=m;j++){
		for(int i=1;i<=n;i++) {
			int k=dp[i][j-1],l=i,r=j-1;
			if(dp[max((int)1,i-1)][j-1]>k){
				k=dp[max((int)1,i-1)][j-1];
				l=max((int)1,i-1);
				r=j-1;
			}
			if(dp[min(n,i+1)][j-1]>k){
				l=min(n,i+1);
				r=j-1;
			}
			trace[i][j]={l,r};
			dp[i][j]=dp[l][r]+a[i][j];
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<"(" << trace[i][j].first << "," << trace[i][j].second << ")" <<" ";
		cout << endl;
	}*/
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(dp[i][m]>sol){
			sol=dp[i][m];x=i;y=m;
		}
	}vector <pair <int, int > > v;
	while(x>0&&y>0){
		v.push_back({x,y});
		int x2=x;
		x=trace[x][y].first;y=trace[x2][y].second;
	}
	cout << sol << "\n";
	for(int i=v.size()-1;i>=0;i--) cout << v[i].first << " " << v[i].second << "\n";
	return 0;
}
