#include <bits/stdc++.h>
using namespace std;
const long long p=1e3+5;
long long a[p][p];
long long m,n;
long long sol=0;
int main(){
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++) {
			cin >> a[i][j];
			
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(a[i][j]!=0)  sol+=a[i][j]*4+1;
			//sol-=min(a[i][j],a[i-1][j]);
			sol-=2*min(a[i][j],a[i+1][j]);
			sol-=2*min(a[i][j],a[i][j-1]);
		//	sol-=min(a[i][j],a[i][j+1]);
			//
			//cout << sol << endl;
		}
	}
	cout << sol;
}
