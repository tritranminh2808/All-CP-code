#include <bits/stdc++.h>
#define int long long
using namespace std;
int xu_li(int n){
	int t=5,tm=0,s=0;
	for(int i=100;i<=n*10;i*=10){
		t+=4*(i/10);
		if(n>=i/2) tm=i/2-1;
		else tm=n;
		if(tm<t) break;
		s+=tm-t+1;
	}
	return s;
}
int test;
signed main(){
	 
	cin >> test;
	while(test--){
		int n; cin >> n;
		cout << xu_li(n) << "\n";
	} 
	return 0;
}
