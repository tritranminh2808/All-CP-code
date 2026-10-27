#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,a,b,c; cin >> n>>a>>b>>c;
		int day=0;
		day+=n/(a+b+c);
		day*=3;
		n%=(a+b+c);
		if(n>0) {
			n-=a;
			day++;
		}
		if(n>0) {
			n-=b;
			day++;
		}
		if(n>0) {
			n-=c;
			day++;
		}
		cout << day << "\n";
		
	}
	return 0;
}
