#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin >> n;
	int p=n/2;
	int q=n-p;
	if(n<=2) cout << (q+1)*(p+1);
	else{
		n-=2;
		int sol=4;
		for(int i=1;i<=n;i++) sol+=(i+2);
		cout << sol;
	}
	return 0;
}
