#include <bits/stdc++.h>
using namespace std;
long long  sol=0;
const long long  p=1e5+5;
long long  t[p];
int   main(){
	long long   n;
	cin >> n;
	long long  a[n];
	for(long long  i=0;i<n;i++)  cin >> a[i];
	vector <long long > v;
	t[0]=a[0];
	v.push_back(a[0]);
	for(long long  i=1;i<n;i++){
		v.push_back(a[i]*(i+1)-t[i-1]);
		t[i]=t[i-1]+v[v.size()-1];
	}
	for(auto i:v) cout << i << " ";
	return 0;
}
