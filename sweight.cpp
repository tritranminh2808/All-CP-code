#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector <int> a(n),sech;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		if(sech.empty()||sech.back()<a[i]) sech.push_back(a[i]);
		else{
			auto it=lower_bound(sech.begin(),sech.end(),a[i])-sech.begin();
			sech[it]=a[i];
		}
	}
	for(auto i : sech) cout << i << ' ';
}
