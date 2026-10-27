#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
	while(q--){
		int k,n; cin >> k >> n;
		vector <int> a(n);
		for(int i=0;i<n;i++) cin >> a[i];
		sort(a.rbegin(),a.rend());
		int cnt=0,meo=0;
		for(int i=0;i<n;i++){
			if(meo>=a[i]) break;
			cnt++;
			meo+=k-a[i]; 
//			cout << meo << endl;
		}
		cout << cnt<< "\n";
	}
}
