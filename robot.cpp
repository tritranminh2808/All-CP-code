#include <bits/stdc++.h>
using namespace std;
int sol=0;
int main(){
	int a,b,c; cin >> a >> b >> c;
	if(a<=100000&&b<=100000){
		int st=a;
		while(st<b){
			if((st+2)%c==0) st++;
			else st+=2;
			sol++;
		}
		cout << sol;
		return 0;
	}
	if(c%2==0) cout <<  (b-a)/2+1;
	else{
		int jump1=(b-(b%c)-(a+(c-a%c)))/c;
		jump1/=2;
		int res=(b-a)/2+jump1;
		if(jump1%2!=0) res++;
//		cout << res;
		cout <<  (c-(a%c))/2+(b%c+2)/2+jump1*(c/2+1);
	}
	
}
