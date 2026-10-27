#include <bits/stdc++.h>
#define int long long
using namespace std;
struct gg{
	int t,m;
	friend bool operator < (gg a, gg b){
		return a.t*b.m<a.m*b.t;
	}
	friend bool operator > (gg a, gg b){
		return a.t*b.m>a.m*b.t;
	}
};
vector <gg> dp;
gg a[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> a[i].t;
	for(int i=0;i<n;i++) cin >> a[i].m;
	for(int i=0;i<n;i++){
//		pair<int, int> cur={a[i].t,a[i].m};
		auto it=lower_bound(dp.begin(),dp.end(),a[i]);
		if(it>=dp.end()) dp.push_back(a[i]);
		else *it=a[i];
	}
	cout << dp.size();
	return 0;
}
