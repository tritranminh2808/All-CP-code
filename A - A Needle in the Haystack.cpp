#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
using ull=unsigned long long;
ull mul(ull a, ull b, ull m){
	if(b==0) return 0;
	ull t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
//ull power(ull a,ull b, ull m) {
//    if (b == 0) return 1;
//
//    ull half = power(a, b/2, m);
//   
//    if (b%2==0) return mul(half,half,m);
//    else return mul(half,mul(half,a,m),m);
//}

int power[1000005];
signed main(){
	
	const int c=31;
	power[0] = 1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	int l;
	 while(cin >> l){
		
		string a; string b;
		cin >> a; cin >> b;
		int lena=a.length(),lenb=b.length();
		
		vector <int > hashT (b.size()+5,0);
		a=" "+a;
		b=" "+b;
		int hashP=0;
		for(int i=1;i<=lena;++i)  hashP = (hashP * c + a[i] - 'a' + 1)%mod;
		for (int i = 1; i <= lenb; i++) hashT[i] = (hashT[i - 1] * c + b[i] - 'a' + 1) % mod;
		for(int i=1;i<=lenb-lena+1;++i){
			int k=(hashT[i+lena-1]-hashT[i-1]*power[lena])%mod;
			if(k<0) k += mod;
			if(hashP==k) cout << i - 1 << "\n";
		//	cout << hashP <<" "<< k << endl;
		}
		cout << "\n";
	}
	return 0;
}
