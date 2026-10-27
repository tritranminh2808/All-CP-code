#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(n);
		queue<int> pq;
		for(int i=0;i<n;i++)cin >> a[i];
		sort(a.begin(),a.end());
		int sol=a[0];
		for(int i=1;i<n;i++){
			sol+=a[i];
			sol--;
		}
		cout << sol << "\n";
	}
	return 0;
	
}
