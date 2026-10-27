#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2005][2005],pre_cheo[2005][2005],pre_sol[2005][2005],pre_cot[2005][2005],pre_hang[2005][2005];
int sol=-1e18;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k; cin >> n >> m>>k;
	for(int i=1;i<=n;i++) { for(int j=1;j<=m;j++) cin >> a[i][j]; }
	for(int i=1;i<=m;i++){ pre_cheo[1][i]=a[1][i];	for(int j=1;j<=min(m,n)-1&&i+j<=m;j++) pre_cheo[1+j][i+j]=pre_cheo[j][i+j-1]+a[1+j][i+j];}
	for(int i=2;i<=n;i++){ pre_cheo[i][1]=a[i][1];for(int j=1;j<=min(m,n)-i;j++) pre_cheo[i+j][1+j]=pre_cheo[i+j-1][j]+a[i+j][1+j];}
	for(int i=1;i<=m;i++){ for(int j=1;j<=n;j++) pre_cot[j][i]=pre_cot[j-1][i]+a[j][i];}
	for(int i=1;i<=n;i++){ for(int j=1;j<=m;j++) pre_hang[i][j]=pre_hang[i][j-1]+a[i][j];}
	int dd=1;
	for(int i=1;i<=k;i++){ for(int j=1;j<=dd;j++) pre_sol[1][1]+=a[i][j];dd++;}
	for(int i=2;i<=n-k+1;i++)pre_sol[i][1]=pre_sol[i-1][1]+pre_hang[i+k-1][k]-pre_cheo[i+k-2][k];
	for(int i=1;i<=n-k+1;i++){ for(int j=2;j<=m-k+1;j++) pre_sol[i][j]=pre_sol[i][j-1]+pre_cheo[i+k-1][j+k-1]-pre_cheo[i-1][j-1]-pre_cot[i+k-1][j-1]+pre_cot[i-1][j-1];}
	for(int i=1;i<=n-k+1;i++){ for(int j=1;j<=m-k+1;j++) sol=max(sol,pre_sol[i][j]);}
	cout << sol;
	return 0;
}
