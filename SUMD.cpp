#include <bits/stdc++.h>
using namespace std;
long long tcs(long long n){
	long long t=0;
	while(n>0){
		t+=n%10;
		n/=10;
	}
	return t;
}
int main(){
//	freopen("SUMD.inp","r",stdin);
//	freopen("SUMD.out","w",stdout);
		long long sol=0,a=1,b; cin >> b;
		if(b<=a+9){
			for(long long j=a;j<=b;j++){
				sol+=j%9;
				if(j%9==0) sol+=9;
			}
		}
		else{
			while(a%9!=0){
				sol+=a%9;a++;
			}
			while(b%9!=0){
				sol+=b%9;b--;
			}
			while(a>b) b+=9;
			sol+=(b-a)/9*45+9;
		}
		cout << sol;
	return 0;
}

