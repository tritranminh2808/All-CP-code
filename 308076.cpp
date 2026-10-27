#include <bits/stdc++.h>
using namespace std;

const int p=1e5;
int a[p];
int main() {
	vector <int> v;
	int n; cin >> n;for(int i=0;i<n;i++) {
		cin >> a[i];
		v.push_back(a[i]);
	}
	for( auto i : v) cout<<char(i);
    return 0;
}
