#include <bits/stdc++.h>
using namespace std;
const int p=1e7+5;
int r[p];
int main()
{

	int n; cin >> n;
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		int k; cin >> k; a.push_back(k);
	}
	reverse(a.begin(),a.end());
	vector <int> v;
	v.push_back(n);
	for(int i=1;i<n;i++){
		v.insert(v.begin()+a[i],n-i);
	}
	for( auto i : v) cout << i << " ";
	return 0;
	
}
