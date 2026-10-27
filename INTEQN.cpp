
#include <bits/stdc++.h>
using namespace std;
unsigned long long a,cstc=0;
long long gcd(long long a, long long b, long long x, long long y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long gcd( long long a, long long b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("inteqn.inp","r",stdin);
//	freopen("inteqn.out","w",stdout);
	long long t; cin >> t;
	for(long long i=0;i<t;i++){
		long long a,b,c,x0,y0; cin >> a >> b>> c;
		long long g = gcd(abs(a), abs(b), x0, y0);
	    if (c % g!=0) {
	        cout << 0 << "\n";
	    }
	
	    else{
	    	x0 *= c / g;
		    y0 *= c / g;
		    if (a < 0) x0 = -x0;
		    if (b < 0) y0 = -y0;
		    cout << x0 << " " << y0 << "\n";
		}
	}
	
	return 0;
}
