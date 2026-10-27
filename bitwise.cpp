#include <bits/stdc++.h>
using ll=unsigned long long;
using namespace std;
//const int mod=(1LL<<64);
void q1(){
	ll x,y; cin >> x >> y;
	cout << (x&y) << "\n";
}
void q2(){
	ll x,y; cin >> x >> y;
	cout << (x|y) << "\n";
}
void q3(){
	ll x,y; cin >> x >> y;
	cout << (x^y) << "\n";
}
void q4(){
	ll x,y; cin >> x >> y;
	if(y>=64) cout << 0 << "\n";
	else cout << (x*(1ULL<<y)) << "\n";
}
void q5(){
	ll x,y; cin >> x >> y;
	cout << (x>>y) << "\n";
}
void q6(){
	ll x,y; cin >> x >> y;
	cout << ((x>>y)&1ULL) << "\n";
}
void q7(){
	ll x,y,v; cin >> x >> y>> v;
	if(y>=64) cout << x << "\n";
	else{
		x=(x&~(1ULL<<y))|(v<<y);
		cout << x << "\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		int ngu=0;
		cin >> ngu;
		if(ngu==1) q1();
		if(ngu==2) q2();
		if(ngu==3) q3();
		if(ngu==4) q4();
		if(ngu==5) q5();
		if(ngu==6) q6();
		if(ngu==7) q7();
	}
	return 0;
}
