#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	int t; cin >> t;
	while(t--){
		long double a,b,c,d,e,f;
		cin >> a >> b >> c >> d >> e >> f;
		if(a==b&&b==c&&c==d&&d==e&&e==f&&a==0) {
			cout << "INFINITE\n";
			return 0;
		}
		if((long double)a/d==(long double)b/e&&(long double)b/e==(long double)c/f&&d!=0&&e!=0&&f!=0) {
			cout << "INFINITE\n";
			return 0;
		}
		else if((long double)a/d==(long double)b/e&&(long double)b/e!=(long double)c/f) {
			cout << "NO SOLUTION\n";
			return 0;
		}
		else if((long double)a/d!=(long double)b/e&&(long double)b/e==(long double)c/f) {
			cout << "NO SOLUTION\n";
			return 0;
		}
		else if((long double)a/d==(long double)c/f&&(long double) a/d !=(long double)b/e) {
			cout << "NO SOLUTION\n";
			return 0;
		}
		
		/* if(a==0){
			long double y=(long double) c/1.0/b;
			cout << "-0.00 " ;
			cout << fixed << setprecision(2) << y;
		}&*/
		else{
			if((int)(a*f-c*d)%(int)(a*e-b*d)!=0||(int)(c-b*y)%a!=0) {
				cout << "NP SOLUTION\n"; 
			}
			else{
				long double y=(long double)(a*f-c*d)/(a*e-b*d);
			long double x=(long double)(c-b*y)/a;
			cout << x  <<" " << y << "\n";
			}
		}
	}
	return 0;
}
