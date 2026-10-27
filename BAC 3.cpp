#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int t; cin >> t;
    while(t--){
    	int a,b,m=0,sech=a;
	    cin >> a >> b;   
	    while (sech>0){
	        m+=sech%3;
	        sech/=3;
	    }
	    if (m<=b&&(b-m)%2==0) cout << "Yes\n";
	    else cout << "No\n";
	}
    return 0;
}

