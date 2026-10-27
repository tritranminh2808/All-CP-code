#include <bits/stdc++.h>
#define int long long
using namespace std;
//char sol[1000005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
    	int n; cin >> n;
//    	vector <int> a(n),b(n);
    	string a,b; cin >> a >> b;
    	int schan=0,sle=0;
    	for(int i=0;i<n;i++){
    		if(i%2==0){
    			sle+=a[i]-'0';
    			schan+=b[i]-'0';
			}
			else{
				sle+=b[i]-'0';
				schan+=a[i]-'0';
			}
		}
		if(sle> n/2||schan>(n+1)/2) cout << "NO\n";
		else cout << "YES\n";
	}
    return 0;
}
 
