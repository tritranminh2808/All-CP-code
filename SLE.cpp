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
		
	
		else{
			long double y=(long double)(a*f-c*d)/(a*e-b*d)*1.0;
			long double x=(long double)(c-b*y)/1.0/a;
			cout << fixed << setprecision(2) << x  <<" " << y << "\n";
		}
	}
	return 0;
}
