#include <bits/stdc++.h>
using namespace std;
long long mod = 26;
int main(){
	long long n;
	cin >> n;
	long long og = n+1;
	if(n%2==0){
		n/=2;
	}else og /=2;
	long long res = ((og%mod)*(n%mod) + mod)%mod;
	cout << (char)(res+65);
}
