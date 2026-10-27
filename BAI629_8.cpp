#include <bits/stdc++.h>
using namespace std;

unsigned long long sol=1;
int main() {
	long long t,n,a,b,c; cin >> t >>n >> a >> b >> c;
	if(t==2)cout << min(a,min(b,c));
	else cout << (long long)a+b+c-2*n;
}
