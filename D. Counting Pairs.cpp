#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,x,y,sum=0,sol=0; cin >> n >> x >> y;
		vector <int> a(n+1),pre(n+1),pre_rm(n+1),congdon(n+1);
		for(int i=1;i<=n;i++){
			cin >> a[i];
			sum+=a[i];
		}
		sort(a.begin(),a.end());
		for(int i=1;i<=n;i++){
		
			auto r=lower_bound(a.begin()+i+1,a.end(),sum-a[i]-y)-a.begin();
			auto l=upper_bound(a.begin()+i+1,a.end(),sum-a[i]-x)-a.begin()-1;
		//	cout << l << " " << r << "\n";
			sol+=l-r+1;
		}
		cout << sol << "\n";
	}
	return 0;
}
