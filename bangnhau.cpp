#include <bits/stdc++.h>
using namespace std;
int sol=0,ss=0;
int main(){
	int n; cin >> n;
	vector <int> v(n);
	for(int i=0;i<n;i++) {
		cin >> v[i];
		ss+=v[i];
	}ss/=n;
//	sort(v.begin(),v.end());
	for(auto i : v) sol+=abs(i-ss)*abs(i-ss);
	cout << sol;
	return 0;
}
