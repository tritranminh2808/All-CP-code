#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
long long lcm(long long a, long long b){
	return (b/gcd(a,b))*(a/gcd(a,b))*gcd(a,b);
}
int scs(long long n){
	int s=0;
	while(n!=0){
		n/=10;s++;
	}
	return s;
}
int main(){
	long long a,b; cin >> a >> b;
	cout << scs(lcm(a,b));
	return 0;
}
