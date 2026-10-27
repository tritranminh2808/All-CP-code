#include <bits/stdc++.h>
using namespace std;
bool snt(long long n){
	if(n<=1){
		return 0;
	}
	for(long long i=2;i*i<=n;++i){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	long long n; cin >> n;
	long long i=n/2;
	while(1){
	//	if(__gcd(i,n-i)!=1&&i!=n-i) i--;
	//	else {
			if(!snt(i)&&!snt(n-i)){
				cout << i << " " << n-i;return 0;
			}
			i--;
	//	}
	}
	return 0;
}
