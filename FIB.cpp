#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e6+5;
unsigned long long fib[p];
//long long mod=1e9+7;
signed main(){
	fib[0]=1;fib[1]=1;
	for(int i=2;i<=100;i++){
		fib[i]=fib[i-1]+fib[i-2];
		
	}
	int t; cin >> t;
	while(t--){
		int a; cin >> a;
		cout << fib[a] << "\n";
	}
}
