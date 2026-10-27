#include <bits/stdc++.h>
using namespace std;
long double cos(int a,int b,int c){
	return (long double)(b*b+c*c-a*a)/(2*b*c)*1.0;
}
long double a, b, c;
int main(){

	cin >> a >> b >> c;

	

	
 	if (a*a == b*b+c*c||c*c ==b*b+a*a||b*b == a*a+c*c) cout << "0";
	
	//else if(cos(a,b,c)>0&&cos(b,a,c)>0&&cos(c,a,b)>0&&cos(a,b,c)<1&&cos(b,a,c)<1&&cos(c,b,a)<1) cout << "1";
	else if(a*a > b*b+c*c||c*c >b*b+a*a||b*b > a*a+c*c) cout << "2";
	else cout << "1";
	

	return 0;
}
