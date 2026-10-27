#include <bits/stdc++.h>
#define int long long
using namespace std;
int l[100005],r[100005],h[100005];
signed main(){
	int n; cin >> n;
	unordered_map<int> start,end;
	set<int> sl;
	multiset<int> st;
	for(int i=0;i<n;i++) {
		cin >> l[i] >> r[i] >> h[i];
		start[l[i]]=r[i];
		end[r[i]]=l[i];
		sl.insert(r[i]);
		sl.insert(l[i]);
	}
	for(auto k: sl){
		if(den[])
	}
	return 0;
}
