#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=1;
signed main(){
	int l,r; cin >> l >> r;
	sol+=(r+l)*(r-l+1)/2;
	for(int i=2;i<=sqrt(r);i++){
		if(i>=l) break;
		int x=r/i;
		if(x*i<=r&&x*i>=l) {
			int y=l/i;
			if(l%i!=0) y++;
			sol+=(x+y)*(x-y+1)/2;
			sol+=i;
			
		}
	}
	cout << sol;
	return 0;
}
