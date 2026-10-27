#include <bits/stdc++.h>
using namespace std;
bool check(int a){
	int k=sqrt(a);
	if(k*k!=a) return false;
	if(k%2==0) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int > a(n);
		for(int i=0;i<n;i++) cin >> a[i];
		int T=0,K=1,sol=0;
	//	sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
			T+=a[i];
			if(check(T)) sol++;
		}
		cout << sol << "\n";
	}
	return 0;
}
