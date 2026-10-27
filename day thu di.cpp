#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >>n;
		vector <int> a(n);
		for(int i=0;i<n;i++) cin >> a[i];
		bool sech=1;
		for(int i=1;i<n;i++){
			if(abs(a[i]-a[i-1])>=2){
				sech=0;
				break;
			}
		}
		if(sech) cout << "NO";
		else cout << "YES";
		cout << "\n";
	}
	return 0;
	
}
