#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main(){
	long long n; cin >> n;
	long long sol=1;
	for(int i=1;i<=n;i++){
		sol*=i;sol%=mod;
	}
	cout << sol;
	return 0;
}
