#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int a[p];
int n;
int main(){
	cin >> n;
	vector <int > v;
	for(int i=0;i<n;i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	
	for(int i=0;i<n;i++){
		cout << lower_bound(v.begin(),v.end(),a[i]) -v.begin() <<" " << v.end()- upper_bound(v.begin(),v.end(),a[i]) << "\n" ;
	}
}
