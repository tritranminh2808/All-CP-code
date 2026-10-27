#include <bits/stdc++.h>
using namespace std;
bool scp(long long n){
	long long k=sqrt(n);
	if(k*k==n) return true;
	return false;
}
long long tong_uoc(long long n){
	unsigned long long sol=0;
	for(int i=1;i<sqrt(n);i++) {
		if(n%i==0) sol+=i+n/i;
	}
	if(scp(n)) sol+=sqrt(n);
	return sol;
}
int main(){
	long long n; cin >> n;
	cout << tong_uoc(n);
	return 0;
}
