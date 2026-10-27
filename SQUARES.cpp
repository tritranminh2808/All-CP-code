#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    long long n;
    cin >> n;
    
    long long a=n,b=n+1,c=2*n+1;
    if(a%3==0) a/=3;
    if(b%3==0) b/=3;if(c%3==0) c/=3;
    if(a%2==0) a/=2;
    if(b%2==0) b/=2;
    long long res=a%mod;
    res=res*(b%mod)%mod;
    res=res*(c%mod)%mod;
    cout << res;
	return 0;
    //cout << (res%mod)*(pow(6,-1)%mod)%mod;
	//cout << (long long)(n*(n+1)%mod*(2*n+1)%mod*(long long)pow(6,-1)%mod)%mod;
  
}

