#include <bits/stdc++.h>
#define int ll
using ll=unsigned long long;
using namespace std;
signed main(){
	freopen("increment.inp","r",stdin);
	freopen("increment.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,a,b; cin >> n >> a >> b;
		int sol=0;
		while(a<=n||b<=n){
			if(a<b){
				a+=b;
				sol++;
			}
			else {
				b+=a;
				sol++;
			}
		}
		cout << sol << "\n";
	}
}
