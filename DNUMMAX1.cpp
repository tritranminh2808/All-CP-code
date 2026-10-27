#include <bits/stdc++.h>
using namespace std;
long long scs(long long n){
	long long scs=0;
	while(n!=0){
		n/=10;scs++;
	}return scs;
}
unsigned long long res(long long n, long long k){
	unsigned long long sol=0;
	while(k>0){
		sol+=n*pow(10,k-1);k--;
	}
	return sol;
}
long long chu_so_dau(long long n){
	return n/pow(10,scs(n)-1);
}
int main(){
	unsigned long long n; cin >> n;
	//cout <<chu_so_dau(n);
	if(res(chu_so_dau(n),scs(n))<=n){
		cout <<res(chu_so_dau(n),scs(n));
	}
	else{
		if(chu_so_dau(n)==1){
			cout << res(9,18);
		}
		else cout << res(chu_so_dau(n)-1,scs(n));
	}
	//cout << res(3,10);
	return 0;
}
