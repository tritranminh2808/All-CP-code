#include <bits/stdc++.h>
#define int ull
using ull=unsigned long long;
using namespace std;
signed main(){
	int k; cin >> k;
	set <pair <int,int> > v;
	for(int a=1;a<=min(k,2000000);a++){
		int x=(a-1)*a*a/2,y=a*(a-1)*(2*a-1)/6,cc=a*a-(a-1)*a/2;
		if((k+x-y)%cc==0) {
			v.insert({a,(k+x-y)/cc});
			v.insert({(k+x-y)/cc,a});
		}
//		cout << a << " " << (k+x-y)/cc << "\n";
	}
	cout << v.size() << "\n";
//	sort(v.begin(),v.end());
	for(auto i :v) cout << i.first << " " << i.second << "\n";
	return 0;
}
