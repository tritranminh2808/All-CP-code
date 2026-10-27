#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,k; cin >> n>>k;
		vector <int> v(n+1);
		
//		v[0]=INT_MAX;
		for(int i=1;i<=n;i++) cin >> v[i];
		int cnt=1,res=1;
		sort(v.begin()+1,v.end());
		for(int i=2;i<=n;i++){
			if(v[i]-v[i-1]<=k) cnt++;
			else cnt=1;
			res=max(res,cnt);
		}
		cout << n-res << "\n";
	}
}
