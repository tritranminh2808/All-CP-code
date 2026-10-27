#include <bits/stdc++.h>
using namespace std;
int f[400005];
bool check(vector <int> v){
	for(int i=0;i<v.size()-1;i++) if(v[i+1]<v[i]) return false;
	return true;
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(n);
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<n-1;i++){
			int x=min(a[i],a[i+1]);
			a[i]-=x;
			a[i+1]-=x;
		}
		if(check(a)) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}
