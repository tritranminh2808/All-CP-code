#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	long long t;
	cin >> t;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(long long p=0;p<t;p++){
		long long n;
		cin >> n; long long a[n];
		for(long long i=0;i<n;i++) {
			cin >> a[i];
		}
		stack<long long> S;
		long long res = 0;
		for (long long i = 0; i < n; ++i)
		{
			while (!S.empty() && S.top() < a[i]) S.pop(); 
			if (a[i] > 0 && (S.empty() || S.top() > a[i]))
			++res; 
			S.push(a[i]);
		}
		cout << res << "\n";
	}
	
	return 0;
}
