#include <bits/stdc++.h>
using namespace std;
int uoc(int a,int b){
	if(b==0) return a;
	else return uoc(b,a%b);
}
int boi(int a,int b){
	return a*b/uoc(a,b);
}
int main()
{
	freopen("FRACSUB.INP","r+",stdin);
	freopen("FRACSUB.OUT","w+",stdout);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	a*=boi(b,d)/b;
	c*=boi(b,d)/d;
	int mau=boi(b,d);
	int tu=a-c;
	int k=uoc(tu,mau);
	tu/=k;mau/=k;
	if(tu<0&&mau<0){
		tu*=-1;mau*=-1;
	}
	else if(tu>0&&mau<0){
		tu*=-1;mau*=-1;
	}
	cout << tu <<" " << mau;
	return 0;
}
