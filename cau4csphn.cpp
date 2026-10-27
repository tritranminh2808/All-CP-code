#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int sol=0;
	int n; cin >> n;
	int k=sqrt(n);
	for(int i=1;i<=k;i++) sol+=n/i;
	sol=2*sol-(k*k);
	cout << sol;
	return 0;
}
