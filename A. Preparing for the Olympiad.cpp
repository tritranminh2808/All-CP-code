#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(n),b(n+1);
		for(int i=0;i<n;++i) cin >> a[i];
		for(int i=0;i<n;++i) cin >> b[i];
		b[n]=0;
		int sn=0,sm=0;
		for(int i=0;i<n;i++){
			if(sn+a[i]-sm-b[i+1]>sn-sm){
				sn+=a[i];
				sm+=b[i+1];
			}
		}
		cout << sn-sm << "\n";
	}
	return 0;
}
