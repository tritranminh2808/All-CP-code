#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("HW22.INP","r+",stdin);
	freopen("HW22.OUT","w+",stdout);
	int a,b,c;cin >>a>>b>>c;
	long long delta=(long long)b*b-4*a*c;
	if(delta<0){
		cout << "vo nghiem";
		return 0;
	}
	if(delta==0) {
		float no=(-b)/(2*a);
		cout << fixed << setprecision(3) << no;
		return 0;
	}
	if(delta>0){
		float no1=(-b+sqrt(delta))/(2*a);
		float no2=(-b-sqrt(delta))/(2*a);
		cout << fixed << setprecision(3) << no1 << " " << no2;
	}
	return 0;
}
