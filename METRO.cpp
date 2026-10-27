#include <bits/stdc++.h>
using namespace std;
long long n,a,x,b,y;
long long d(long long p, long long q){
	return (q+n-p)%n; 
}
bool check()
{
	long long ab=d(a,b);
	long long abn=ab+n;
	long long ax=d(a,x);
	long long by=d(y,b);
	return (ab%2==0 && ax>=ab/2 &&by>=ab/2)||(abn%2==0&&ax>=abn/2&&by>=abn/2);
	

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    long long q;
    cin >> q;
    while (q--) {
       
        cin >> n >> a >> x >> b >> y;
		if(check()){
			cout << "YES\n";
		}
		else cout << "NO\n";/*
        bool found = false;
        while (a != x && b != y) {
            if (a == b) {
                found = true;
                break;
            }
            a = (a % n) + 1;      
            b = (b == 1) ? n : b - 1; 
        }

        if (a == b || found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }*/
    }
    return 0;
}

