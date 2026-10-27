#include <bits/stdc++.h>
using namespace std;
long long lt[17];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

//	for(int i=1;i<=16;i++) cout << lt[i] << " ";
	int t; cin >> t;
	while(t--){
		long long n,k;
		cin >> n >> k;
		if(n<=63&&k>(1LL<<(n-1))) {
			cout << -1 << "\n";
			continue;
		}
		vector <int> bit;
		k--;
		while(k!=0){
			bit.push_back(k%2);
			k/=2;
		}
		while(bit.size()<n-1) bit.push_back(0) ;
		reverse(bit.begin(),bit.end());
//		for(auto i :bit) cout << i;
		vector <int> v(n+1);
		int l=1,r=n,id=1;
		while(l<=r){
			if(id==n) {
				v[l]=id;
				break;
			}
			if(bit[id-1]==0)v[l++]=id;
			else v[r--]=id;
			id++;
		}
		for(int i=1;i<=n;i++) cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}
