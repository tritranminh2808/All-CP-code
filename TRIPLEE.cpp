#include <bits/stdc++.h>
#pragma GCC optimize ("03,unroll-loops")
using namespace std;
long long  scs(long long  n){
	long long  d=0;
	if(n==0) return 1;
	while(n!=0){
		n/=10;
		d++;
	}
	return d;
}
long long  xu_li(long long  n, long long  k){
	if(k==0) return n;
	long long  t;
	vector <long long  > v;
	while(n!=0){
		t=n%10;
		n/=10;
		v.push_back(t*3);
	}
	n=0;
	reverse (v.begin(),v.end());
	for(auto i:v){
		n*=pow(10,scs(i));
		n+=i;
	}
	k--;
	return xu_li(n,k);
}
int  main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long  t; cin >> t;
	while(t--){
		long long  n,k;
		cin >> n >> k;
		cout << xu_li(n,k)%123456789 << "\n";
	}
	return 0;
}
