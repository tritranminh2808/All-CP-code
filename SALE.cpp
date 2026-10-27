#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main(){
	long long n,p,k; cin >> n >> k >> p;
	unsigned long long t= p *(n  / ( k + 1 ) )*k + p * (n % ( k + 1 ));
	//while(t/p+t/p/k<n) t++;
	
	cout << t;
	return 0;
}
