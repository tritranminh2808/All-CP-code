#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b){
	return a/__gcd(a,b)*b/__gcd(a,b)*__gcd(a,b);
}
int main(){
	int t; cin >> t;
	for(int i=0;i<t;i++){
		long long a,b,c; cin >> a >> b >> c;
		long long x=lcm(a,b)/a,y=lcm(b,c)/b,z=lcm(c,a)/c;
		cout << lcm(x,lcm(y,z)) << endl;
		//cout << x << " " << y << " " << z;
		
	}
}
