#include <bits/stdc++.h>
using namespace std;
long long cnt=0;
int main(){
	int n,k; cin >> n >> k;
	vector <int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	int med=0;
	if(n%2==1) med= a[n/2];
	else med=(a[n/2]+a[n/2-1])/2;
	for(int i=0;i<n;i++) cnt+=abs(a[i]-med);
	cout << cnt;
	return 0;
}
