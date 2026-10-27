#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],l[1000005],r[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>> t;
	while(t--){
		int a,b; cin >> a >> b;
		int x=sqrt(a),y=sqrt(b);
		cout << x*b+y*a-2*x*y << "\n";
	}
	return 0;
}
