#include <bits/stdc++.h>
#define int long double
using namespace std;
vector <pair <int ,int > > a;
int n;
const long double ee=1e-7;
bool check(long double R){
	for(auto i:a) if(R*2<i.second) return false;
//	vector <pair <long double, long double > > v;
	long double curl=-DBL_MAX,curr=DBL_MAX;
	for(auto i:a){
		long double K=R*R-(i.second-R)*(i.second-R);
		K=sqrt(K);
		int k1=i.first-K,k2=i.first+K;
		curl=max(curl,k1);
		curr=min(curr,k2);
	}
	return curl<=curr+ee;
}
void cook(){
	long double res=100000000.0;
	long double ly=0,ry=1e16;
//	bool sech=0;
	int l2=300;
	while(l2--){
		long double midy=(ly+ry)/2;
		if(check(midy)) {
			ry=midy;
			res=midy;
		}
		else ly=midy;
	}
//	if(res==100000000.0) cout << -1;
	cout << fixed << setprecision(6) << (long double)res;
}
bool am,duong;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		int x,y; cin >> x >> y;
		if(y<0) am=1;
		if(y>0) duong=1;
		if(am)	y=abs(y);
		
		a.push_back({x,y});
	}
	if(am&&duong) {
		cout << -1;
		return 0;
	}
	cook();
	return 0;
}
