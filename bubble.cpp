#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector <int> a(n) ;
	for(int i=0;i<n;i++) cin >> a[i];
	int t=1;
	while(t<=n-1){
		for(int i=0;i<n-1;i++) if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		t++;
		for(auto i : a) cout << i << " ";
		cout << "\n";
	}
	return 0;
}
