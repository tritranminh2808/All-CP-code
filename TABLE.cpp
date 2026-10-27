#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n; cin >> n;
	long long b=sqrt(n);
	long long k=b; while(b*k<n) k++;
	cout << b << " " << k;
	return 0;
}

