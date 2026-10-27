#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")
using namespace std;
const long long  p=1e7+5;
long long  r[p];
long long s,t;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long  n; cin >> n;
	long long  a[n];
	for (long long  i=0;i<n;i++) {
		cin >> a[i];s+=a[i];
	}
	
	s/=n;
	for(long long  i=0;i<n;i++){
		if(a[i]>=s) {
			t+=a[i]-s;
		}
	
	}
	cout << t;
	return 0;
}
