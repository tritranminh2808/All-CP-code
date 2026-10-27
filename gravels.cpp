#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=0;
int pre[1000005];
signed main(){
	int n; cin >> n;
	vector <int> a(n+1);
//	vector <pair <int, int > > thieu, thua;
	int aver=0;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		aver+=a[i];
	}
	aver/=n;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		sol+=abs(pre[i]-aver*i);
	}
	cout << sol;
	return 0;
}
