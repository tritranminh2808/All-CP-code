#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector <int> a(n);
		bool check=0;
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<n;i++){
			if((a[i]-i)%2!=0) {
				check=1;
				break;
			}
		}
		if(check==1) cout << "K\n";
		else cout << "D\n";
	}
	
	return 0;
}
