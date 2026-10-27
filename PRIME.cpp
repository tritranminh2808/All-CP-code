#include <bits/stdc++.h>
using namespace std;
bool snt(long long n){
	for(long long i=2;i*i<=n;++i){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	long long n; cin >> n;
	if(n<=1){
		cout << "NO";return 0;
	}
	if(snt(n)){
		cout << "YES";return 0;
	}
	cout << "NO";
	return 0;
}
