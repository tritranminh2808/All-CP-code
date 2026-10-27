#include <bits/stdc++.h>
using namespace std;
int main(){
	long double a,b,c; cin >> a >> b >> c;
	long double p=(a+b+c)/2;
	long double pi=atan(1)*4;//3.14159265358979323846;
	long double S_tamgiac=sqrt(p*(p-a)*(p-b)*(p-c));
	long double ban_kinh_noi_tiep=S_tamgiac/p;
	long double ban_kinh_ngoai_tiep=a*b*c/4/S_tamgiac;
	long double red=pow(ban_kinh_noi_tiep,2)*pi;
	long double purple=(long double)S_tamgiac-red;
	long double yellow=pow(ban_kinh_ngoai_tiep,2)*pi-S_tamgiac;
	cout << fixed << setprecision(4) << yellow << " " << purple << " " << red;
	return 0;
}

