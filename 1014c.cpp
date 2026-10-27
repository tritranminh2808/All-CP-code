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
    	vector <int> a(n),b(n);
    	int k=0,s=0,p=0,s2=0;
    	for(int i=0;i<n;i++){
    		int x; cin >> x;
    		if(x%2==1)k++;
			else s2++;
			p=max(p,x);
    		s+=x;
		}
		if(s2>0&&k>0) cout << s-k+1 << "\n";
		else cout << p << "\n";
	}
    return 0;
}
 
