#include <bits/stdc++.h>
#define int long long
using namespace std;
int c=257;
const int mod=1e9+7;
int hashT[100005],power[100005];
string a;
int n;
bool cook(int sech){
	int base=(hashT[sech]-hashT[0]*power[sech])%mod;
	if(base<0) base+=mod;
	for(int i=sech;i<=n;i+=sech){
		int k=(hashT[i]-hashT[i-sech]*power[sech])%mod;
		if(k<0)k+=mod;
		if(k!=base) return false;
	}
	return true;
}
signed main(){
	power[0]=1;
	for(int i=1;i<=100000;i++) power[i]=power[i-1]*c%mod;
	cin >> a;
	n=a.length();
	a='!'+a;
	for(int i=1;i<=n;i++)hashT[i]=(hashT[i-1]*c+a[i]+1)%mod;
	vector <int> v;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			v.push_back(i);
			v.push_back(n/i);
		}
	}
	sort(v.begin(),v.end());
//	cook(3);
	for(auto i : v){
//		cout << i <<  ": ";
		if(cook(i)) {
			for(int j=1;j<=i;j++) cout << a[j];
			break;
		}
	}
	return 0;
}
