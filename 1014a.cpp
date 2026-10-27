#include <bits/stdc++.h>
#define int long long
using namespace std;
char sol[1000005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
    	int n; cin>> n;
    	vector <int > a(n);
    	int l=8721837123,r=-1827382173;
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    		l=min(a[i],l);
    		r=max(a[i],r);
		}
    	cout << r-l << "\n";
	}
    return 0;
}
 
