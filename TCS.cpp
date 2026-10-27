#include<bits/stdc++.h>
using namespace std;
long long n,a,t=0,sl=0;
int main(){
	freopen("TCS.INP","r",stdin);
	freopen("TCS.OUT","w",stdout);
	cin>>n;
	a=n;
	while(n>0){
		sl+=n%10;
		n/=100;
	}
	while(a>0){
		int m=a%10;
		if(m%2!=0) t+=m;
		a/=10;
	}
	cout<<sl<<"\n"<<t;
}
