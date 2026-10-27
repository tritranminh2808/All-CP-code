#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
ull mul(ull a, ull b, ull m){
	if(b==0) return 0;
	ull t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
ull power(ull a,ull b, ull m) {
    if (b == 0) return 1;

    ull half = power(a, b/2, m);
   
    if (b%2==0) return mul(half,half,m);
    else return mul(half,mul(half,a,m),m);
}
bool check(ull n){
	ull k=sqrt(n);
	if(k*k==n) return true;
	else return false;
}
int mod=20122007;
ull sol=1;
int main() {
	
    ull n; cin >> n;
    vector <int > v;
    for(int i=1;i<sqrt(n);++i){
    	if(n%i==0) {
    		v.push_back(i);
    		v.push_back(n/i);
		}
	}
	if(check (n)) v.push_back(sqrt(n));
	for(auto i:v){
		sol=mul(sol,power(3,i,mod)-1,mod);
	} 
	cout << sol;
    return 0;
}

