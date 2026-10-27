#include <bits/stdc++.h>
using namespace std;
int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long x=__gcd(a,b),y=__gcd(c,d);
        a/=x;b/=x;c/=y;d/=y;
    	long long r = a % b,r2=a/b;
        vector <long long> v;
        for (long long i = 1; i <= 100; ++i) {
        	r *= 10;
            v.push_back(r/b);
            r %= b;
        }
        //for(long long i=0;i<100;i++) cout << v[i];
        long long l = c % d,l2=c/d;
        if(r2>l2){
        	cout << 1 << endl;
		}
		else if(r2<l2){
			cout << -1 << endl;
		}
        else {
        	vector <long long> v2;
	        for (long long i = 1; i <= 100; ++i) {
	            l *= 10;
	            v2.push_back(l/d);
	            l %= d;
	        }
	        bool check=0;
			for(long long i=0;i<v.size();i++){
				if(v[i]>v2[i]){
					cout << 1 << endl;
					check=1;
					break;
				}
				if(v[i]<v2[i]){
					cout << -1 << endl;
					check=1;
					break;
				}
			}
			if(check==0){
				cout << 0 << endl;
			}
		}
		
    
    }
    return 0;
}
