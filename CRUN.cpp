#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,n; cin >> n >> a>>b;
	cout << (long long)min((b-a+n)%n,(a-b+n)%n);
	return 0;
}
