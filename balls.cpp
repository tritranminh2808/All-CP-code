#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=0;
signed main(){
	int n,m; cin >> n >> m;
	vector <int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	multiset<int> st;
	for(int i=0;i<m;i++){
		int x; cin >> x;
		st.insert(x);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		if(st.size()<=1||a[i]<=*st.begin()||st.upper_bound(a[i])==st.end()) continue;
		auto k=st.lower_bound(a[i]);
		auto z=prev(k);
		st.erase(z);
		auto k2=st.upper_bound(a[i]);
		st.erase(k2);
		sol++;
//		cout << *prev(k) << *k2;
	}
	cout << sol;
	return 0;
}
