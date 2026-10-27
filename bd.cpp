#include <bits/stdc++.h>
#define int long long
using namespace std;
const int z=1e5+5;
int a1[z],t1[z],c1[z],a2[z],t2[z],c2[z],hash1[z],hash2[z];
bool cmp(int a, int b){
	return a>b;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin>> n>>q;
	vector <int > a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end(),cmp);
	while(q--){
		int x; cin >> x;
		int c=0,cnt=0;
		
		while(x>0){
			int maxx=0;
			for(int i=0;i<n;i++){
				maxx=max(maxx,x%a[i]);
			}
			if(maxx==0){
//				cout << -1
				c=1;
				break;
			}
			x=x-maxx;
			cnt++;
		}
		if(c!=1) cout << cnt << "\n";
		else cout << "oo\n";
	}
}
