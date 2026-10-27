#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],l[1000005],r[1000005];
bool cmp(int a, int b){
	return a>b;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>> t;
	while(t--){
		int n; cin >> n;
		if(n%2==0){
			cout << -1 << "\n";
		}
		else{
			int id=1;
			for(int i=1;i<=n;i++){
				int x=(i+id)%n;
				if(x==0) cout << n << " ";
				else cout << x << " ";
				id++;
			}
			cout << "\n";
		}
	}
	return 0;
}
