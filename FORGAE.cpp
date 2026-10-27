#include <bits/stdc++.h>
using namespace std;
const int p=1e7+5;
int r[p];
long long s,t;
int main()
{
	int n; cin >> n;
	int a[n];
	for (int i=0;i<n;i++) {
		cin >> a[i];s+=a[i];
	}
	
	s/=n;
	for(int i=0;i<n;i++){
		t+=abs(a[i]-s);
	}
	cout << t ;
	return 0;
}
