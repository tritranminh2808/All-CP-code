#include<bits/stdc++.h>
using namespace std;
long long tcs(long long a){
	long long t=0;
	while(a!=0){
		t+=a%10;a/=10;
	}
	return t;
}
long long sol=0;
int main()
{
	long long a,b; cin >> a >> b;
	if(a>b) swap(a,b);
	while(a!=0){
		sol+=a%10*tcs(b);
		a/=10;
	}
	cout << sol;
	return 0;
}
