#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> v(n+1);
		bool check=0;
		for(int i=1;i<=n;i++) cin >> v[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(v[i]==j&&v[j]==i) {
					check=true;
					break;
				}
			}
			if(check) break;
		}
		if(check)cout << 2;
		else cout << 3;
		cout << "\n";
	}
}
