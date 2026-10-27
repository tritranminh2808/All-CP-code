#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair <int ,int > a, pair <int, int > b){
	if(a.second==b.second) return a.first < b.first;
	return a.second <b.second;
}
int pre[1000000],t1[1000000],t2[1000000],minn[1000000],m[1000000];
signed main(){
	int n; cin >> n ;vector <pair < int, int > > v (n+1);
	for(int i=1;i<=n;i++) cin >> v[i].first >> v[i].second;
	sort(v.begin()+1,v.end(),cmp);
	minn[n+1]=1000000000000000000;
	for(int i=1;i<=n;i++) {
		pre[i]=pre[i-1]+v[i].second;
		t1[i]=t1[i-1]+v[i].second;
//		minn[i]=min(v[i].first,minn[i-1]);
	}
	m[0]=-1000000000000000000;
	for(int i=1;i<=n;i++){
		m[i]=max(m[i-1],v[i].second-v[i].first);
	}
	for(int i=n;i>=0;i--){
		 minn[i]=min(minn[i+1],v[i].first);
	}
	for(int i=1;i<=n;i++){
		cout << min(t1[i]-m[i],pre[i-1]+minn[i]) << "\n";
	}
	return 0;
}
