#include <bits/stdc++.h>
using namespace std;
const int p=1e3+4;
int sum[p][p];
int sol=0;
int main(){
	//freopen ("TABLE24.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	int a[405][405];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			cin >> a[i][j];
			sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
			for(int u=1;u<=i;u++){
				for(int v=1;v<=j;v++){
					if((sum[i][j]+sum[u-1][v-1]-sum[u-1][j]-sum[i][v-1])%k==0) sol++;
					//cout << u << " "  << v << " " << i << " " << j << ": " << sum[i][j]+sum[u-1][v-1]-sum[u-1][j]-sum[i][v-1] << "\n";
				}
			}
		}
	}
	cout << sol << " ";
	return 0;
}
