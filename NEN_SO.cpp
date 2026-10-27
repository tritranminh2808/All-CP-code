#include <bits/stdc++.h>

unsigned long long mul(long long a, long long b, long long m){
	if(b==0) return 0;
	long long t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
unsigned long long power(long long a,long long b, long long m) {
    if (b == 0) return 1;

    unsigned long long half = power(a, b/2, m);
   
    if (b%2==0) return mul(half,half,m);
    else return mul(half,mul(half,a,m),m);
}
using namespace std;
int main() {
	
    long long n,m; cin >> n >> m;

    cout << mul(n+1,power(2,n-2,m),m)%m;
    return 0;
}

