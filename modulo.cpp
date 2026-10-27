#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	long long a; cin >> a;
	long long x=0;
	int x1=0,x2=0,x3=0;
	if(a%3==0){
		x1=a/3;
		if(a%2==0){
			x2=(a+2)/2;
			x3=a+1;
		}
		else{
			x2=(a+1)/2;
			x3=a+2;
		}
	}
	else if(a%3==1){
		x1=(a+2)/3;
		if(a%2==0){
			x2=a/2;
			x3=a+1;
		}
		else{
			x2=(a+1)/2;
			x3=a;
		}
	}
	else {
//		cout << "jsahd";
		x1=(a+1)/3;
		if(a%2==0){
			x2=a/2;
			x3=a+2;
		}
		else{
			x1/=2;
			x2=a;
			x3=a+2;
		}
	}
	cout << (long long)(x1%2018*x2%2018*x3%2018)%2018;
	return 0;
//	cout << (long long)a*(a+1)*(a+2)/6%2018;
}
