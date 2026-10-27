#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(int n){
	int k=sqrt(n);
	if(k*k==n) return true;
	return false;
}
signed main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(check(n*(n+1)/2)) cout << -1;
		else{
			vector <int> v(n+1);
			for(int i=1;i<=n;i++) v[i]=i;
			int t=0;
			for(int i=1;i<=n-1;i++){
				t+=v[i];
				if(check(t)){
					t-=v[i];
					t+=v[i+1];
					swap(v[i],v[i+1]);
					
				}
			}
			for(int i=1;i<=n;i++) cout << v[i] << " ";
		}
		cout << "\n";
	}
}
