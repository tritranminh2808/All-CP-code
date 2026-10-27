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
	long long n;
	cin >> n;
	int i=0;
	while (1){
		long long a,b;
		if(snt(n-i)){
			cout << n-i;return 0;
		}
		else {
			if(snt(n+i)){
				cout << n+i;return 0;
			}
			i++;
		}
	}
	return 0;
}
