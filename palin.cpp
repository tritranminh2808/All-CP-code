#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
bool check(int n){
	vector <int> v; while(n!=0){
		v.push_back(n%10);
		n/=10;
	}	
	for(int i=0;i<v.size()/2;i++){
		if(v[i]!=v[v.size()-i-1]) return false;
	}
	return true;
}
int  xu_li(int n){
	int k=0;
	while(n!=0){
		k*=10;
		k+=n%10;
		n/=10;
	}
	return k;
}
signed main(){
	int n; cin >> n;
	n+=xu_li(n);
	while(check(n)!=true){
		n+=xu_li(n);
	}
	cout<< n;
}
