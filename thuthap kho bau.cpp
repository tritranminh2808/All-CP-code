#include <bits/stdc++.h>
using namespace std;
long long dp[3001][10001];
struct p{
	long long w, v;
};
bool cmp(p a, p b){
	if(a.w!=b.w){
		return a.w<b.w;
	}else return a.v>b.v;
}
int A[100005],B[100005];
int main(){
	int n, m;
	cin >> n >> m;
	vector<p> a(n);
	for (int i = 0;i<n;++i){
		cin >> a[i].w >> a[i].v >> A[i] >> B[i];
	}
	dp[0][0] = 0;
	sort(a.begin(),a.end(), cmp);
	for (int j = 1;j<=m;++j){
		for(int i = 1;i<=n;++i){
			if(j < a[i-1].w){
				dp[i][j] = dp[i-1][j];
			}else{
				long long du2 = j-a[i-1].w;
				long long t2 = a[i-1].v + dp[i][du2];
				dp[i][j] = max(t2, dp[i-1][j]);
			}
		}
	}
	cout << dp[n][m];

}
