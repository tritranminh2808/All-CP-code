#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(3,0);
		int cnt=0;
		while(a[0]!=n||a[1]!=n||a[2]!=n){
			
			for(int i=0;i<3;i++){
				int m=1e18;
				for(int j=0;j<3;j++){
					if(j==i) continue;
					m=min(m,a[j]);
				}
				if(a[i]<n){
					a[i]=m*2+1;
					if(a[i]>n) a[i]=n;
					cnt++;
				}
			}
//			cout << a[0] << " " << a[1] << " " << a[2] << "\n";
		}
		cout << cnt << "\n";
	}
	return 0;
	
}
