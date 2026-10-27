#include <bits/stdc++.h>
using namespace std;
bool check[1000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, q; cin>> n >> q;
		for(int i=0;i<=n;i++) check[i]=0;
		while(q--){
			int a,b,c; cin >> a >> b >> c;
			check[b]=1;
		}
		int cen=0;
		for(int i=1;i<=n;i++) {
			if(check[i]==0){
				cen=i;break;
			}
		}
		for(int i=1;i<=n;i++){
			if(i!=cen) cout << cen << " " << i << "\n";
		}
	}
}
