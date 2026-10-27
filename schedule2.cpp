#include <bits/stdc++.h>
#define int long long
using namespace std;
int s=0;
int sol[100000];
signed main(){
	int n,k;
	cin >> n >> k;
	vector <pair <int, int > > v;
	int c1=0;
	for(int i=0;i<n;i++){
		int l,r; cin >> l >> r;
		sol[i]=l;
		c1+=r;
		s+=l;
		v.push_back({l,r});
	}
	if(c1<k||s>k) {
		cout << -1; return 0;
	}
	for(int i=0;i<n;i++){
		if(k-s+v[i].first<v[i].second) {
			sol[i]+=k-s;
			break;
		}
		else {
			s+=v[i].second;
			sol[i]=v[i].second;
		}
	}
	for(int i=0;i<n;i++) cout << sol[i] << " ";
}
