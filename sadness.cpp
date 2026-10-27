#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i]=a[i]-i-1;
	}
	int sol=0;
	sort(a.begin(),a.end());
	int sech=a[n/2];
	for(int i=0;i<n;i++) sol+=abs(a[i]-sech);
	cout << sol;
	return 0;
}
