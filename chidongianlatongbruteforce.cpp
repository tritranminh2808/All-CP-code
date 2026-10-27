#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[100005];
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m;
	
	cin >> n ;
	for(int i=1;i<=n;i++) cin >> a[i];
	cin >> m;
	while(m--){
		int k; cin >> k;
		if(k==1){
			int x,y,k1;cin >> x >> y >> k1;
			for(int i=x;i<=y;i++) a[i]+=k1;
		}
		else{
			int aa,b; cin >> aa >> b;
			int s=0;
			for(int i=aa;i<=b;i++) s+=a[i];
			cout << s << "\n";
		}
	}
}
