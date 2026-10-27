#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c;
	cin >> a >> b >> c;
	cout << (long long)gcd(abs(a-b),gcd(abs(b-c),abs(c-a)));
	return 0;
}
