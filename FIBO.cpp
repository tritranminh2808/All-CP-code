#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
unsigned long long fib[p];
int main(){
	int n; cin >> n;
	if(n==0){
		cout << 0;return 0;
	}
	fib[0]=1;fib[1]=1;
	for(int i=2;i<n+5;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout << fib[n+1];
}
