#include <bits/stdc++.h>
using namespace std;
long long sol;
int main(){
	ios_base::sync_with_stdio(0);
	long long n;
	cin >> n;
	for(long long i=1;i<=n;i++){
		sol+=n/i;
	}
	cout << sol;
	return 0;
}
