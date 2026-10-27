#include <bits/stdc++.h>
using namespace std;
using ull=  unsigned long long ;
int main(){
	ull a,b;cin >> a >> b;
	cout << __gcd(a,b)<<"\n" << a/__gcd(a,b) << " " << b/__gcd(a,b); 
}
