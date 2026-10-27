#include <bits/stdc++.h>
using namespace std;
bool check(long long a, long long b,long long t, long long h){
	if(a+b==t&&b-a==h&&a>=0&&b>=0) return true;
	return false;
}
int main() {
   long long t; cin >> t;
   while(t--){
   		long long a,b,c,d; cin >> a >> b >> c >> d;
   		if(check(a,b,c,d)||check(a,b,d,c)){
   			cout << a << " " << b << "\n";
		}
		else if(check(b,a,c,d)||check(b,a,d,c)){
   			cout << b << " " << a << "\n";
		}
		else if(check(a,c,b,d)||check(a,c,d,b)){
   			cout << a << " " << c << "\n";
		}
		else if(check(c,a,b,d)||check(c,a,d,b)){
   			cout << c << " " << a << "\n";
		}
		else if(check(a,d,b,c)||check(a,d,c,b)){
   			cout << a << " " << d << "\n";
		}
		else if(check(d,a,b,c)||check(d,a,c,b)){
   			cout << d << " " << a << "\n";
		}
		else if(check(b,c,a,d)||check(b,c,d,a)){
   			cout << b << " " << c << "\n";
		}
		else if(check(c,b,a,d)||check(c,b,d,a)){
   			cout << c << " " << b << "\n";
		}
		else if(check(b,d,a,c)||check(b,d,c,a)){
   			cout << b << " " << d << "\n";
		}
		else if(check(d,b,a,c)||check(d,b,c,a)){
   			cout << d << " " << b << "\n";
		}
		else if(check(c,d,a,b)||check(c,d,b,a)){
   			cout << c << " " << d << "\n";
		}
		else if(check(d,c,a,b)||check(d,c,b,a)){
   			cout << d << " " << c << "\n";
		}
   }
    return 0;
}

