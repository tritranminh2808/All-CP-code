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
	int t; cin >> t;
	while(t--){
		long long sol=0,a,b; cin >> a >> b;
		//while(a>=10) a=tcs(a);while(b>=10) b=tcs(b);
	//	if(a>b) b+=9;
		if(b<=a+9){
			for(long long j=a;j<=b;j++){
				sol+=j%9;
				if(j%9==0) sol+=9;
			}
		}
		else{
			while(a%9!=0){
				sol+=a%9;a++;
			//	if(a%9==0) sol+=9;
			}
			while(b%9!=0){
				sol+=b%9;b--;
			}
			while(a>b) b+=9;
			sol+=(b-a)/9*45+9;
		}
		//while(sol>=10) sol=tcs(sol);
		cout << sol  << "\n";
	}
//	for(int i=1;i<=100;i++) cout << tcs(i) <<" ";
	return 0;
}
