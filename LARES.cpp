#include <bits/stdc++.h>
using namespace std;
int main(){
	long long m,n,k; cin >> m >> n >>k;
	cout << min(m/2,min(n,(m+n-k)/3));
	return 0;
}
