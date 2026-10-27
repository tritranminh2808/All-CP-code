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
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;++i){
			sum[i][j]=sum[i-1][j]+a[i][j]/*+ sum[i][j-1]-sum[i-1][j-1]*/;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int l=1;
		for(int j=1;j<=m;j++) {
			cout << sum[i][j] << " ";
			if(sum[i][j]%k==0){
				sol+=l;
				l++;
			}
		}
		cout << endl;
	}
	
	//cout << sol << " ";
	return 0;
}
