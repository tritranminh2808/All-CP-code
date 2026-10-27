#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin >> t;
	while(t--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(c>=b&&a>=b)  cout << "Gellyfish\n";
        else if(d>a) cout << "Flower\n";
        else if(c>=d) cout << "Gellyfish\n";
        else cout << "Flower\n";
	}
	return 0;
	
}
