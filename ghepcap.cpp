#include <bits/stdc++.h>
#define int long long
using ull=unsigned long long;
using namespace std;
int sol;
int ss=0,l=9999999,r=-9999999;
signed main(){
	int n; cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	for(int i=0;i<n-1;i++){
		int k=10*a[i]/9;
		auto it=upper_bound(a.begin()+i+1,a.end(),k)-a.begin()-1;
		sol+=it-i;
		//cout << i1 << " " << i2;
	//	cout << sol << "\n";
	}
	cout << sol;
	return 0;
}
