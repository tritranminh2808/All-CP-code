#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int, int > a , pair <int,int> b){
	return a.second> b.second;
}
int main(){
	int n; cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	int t; cin >> t;
	while(t--){
		int ind; cin >> ind;
		auto it= lower_bound(a.begin(),a.end(),ind)-a.begin();
		cout << n-it << "\n";
	}
	return 0;
}
