#include <bits/stdc++.h>
using namespace std;
int a[1005][1005],b[1005][1005],c[1005][1005];
const int mod=1e9+7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   	int n,m,p,q; cin >> n >> m >> p >> q;
   	if(m!=p) {
   		cout << -1;
		return 0;	
	}
   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++) cin >> a[i][j];
	}
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++) cin >> b[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<q;j++){
			for(int k=0;k<m;k++) c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<q;j++) cout << c[i][j] << " ";
		cout << "\n";
	}
    return 0;
}
 
