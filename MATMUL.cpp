#include <bits/stdc++.h>
using namespace std;
const long long pp=1e3+5;
long long a[pp][pp],b[pp][pp],c[pp][pp];
long long m,n,p;
long long sol=0;
int main(){
	cin >> m >> n >> p;
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++) cin >> a[i][j];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=p;j++) cin >> b[i][j];
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=p;j++) {
			for(int k=1;k<=n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p;++j) cout << c[i][j] << " ";
		cout << endl;
	}
}
