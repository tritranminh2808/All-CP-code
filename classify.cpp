#include <bits/stdc++.h>
using namespace std;
string a[10005],b[10005];
int sol=0;
int main(){
	int n,m; cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	for(int j=0;j<m;j++){
		int s1=0,s2=0;
		for(int i=0;i<n;i++){
			if(a[i][j]=='A') s1 |= (1ll << 0);
			if(a[i][j]=='C') s1 |= (1ll << 1);
			if(a[i][j]=='G') s1 |= (1ll << 2);
			if(a[i][j]=='T') s1 |= (1ll << 3);
		}
		for(int i=0;i<n;i++){
			if(b[i][j]=='A') s2 |= (1ll << 0);
			if(b[i][j]=='C') s2 |= (1ll << 1);
			if(b[i][j]=='G') s2 |= (1ll << 2);
			if(b[i][j]=='T') s2 |= (1ll << 3);
		}
//		cout << s1 <<   " " << s2 << " " << (s1&s2) << endl;
		if((s1&s2)==0) sol++;
	}
	cout << sol;
	return 0;
}
