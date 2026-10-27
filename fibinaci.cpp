#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, mod2=1e9+9;
using ull=unsigned long long;
ull mul(ull a, ull b, ull m){
	if(b==0) return 0;
	ull t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
const int c=31,c2=37;
int power[1000005],power2[1000005];
int cok(string a, string b){
	int lena=a.length(),lenb=b.length();
	vector <int > hashT (b.size()+5,0),hashT2(b.size()+5,0);
	a=" "+a;
	b=" "+b;
	int hashP=0,hashP2=0;
	for(int i=1;i<=lena;++i)  hashP = (hashP * c + a[i] - 'A' + 1)%mod;
	for(int i=1;i<=lena;++i)  hashP2 = (hashP2 * c2 + a[i] - 'A' + 1)%mod2;
	for (int i = 1; i <= lenb; i++) hashT[i] = (hashT[i - 1] * c + b[i] - 'A' + 1) % mod;
	for (int i = 1; i <= lenb; i++) hashT2[i] = (hashT2[i - 1] * c2 + b[i] - 'A' + 1) % mod2;
	bool chck=0;
	int ans=0;
	for(int i=1;i<=lenb-lena+1;++i){
		int k=(hashT[i+lena-1]-hashT[i-1]*power[lena])%mod;
		int k2=(hashT2[i+lena-1]-hashT2[i-1]*power2[lena])%mod2;
		if(k<0) k += mod;
		if(k2<0) k2+=mod2;
		if(hashP==k&&hashP2==k2)ans++;
		//	cout << hashP <<" "<< k << endl;
	}
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	power[0] = 1;
	power2[0]=1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	for(int i = 1; i <= 1e6; i++) power2[i] = power2[i - 1] * c2 % mod2;
    int x; while(cin>> x){
        string s; cin >> s;
        vector <string> v(x);
        v[0]='A';
        v[1]='B';
        for(int i=2;i<x;i++) v[i]=v[i-1]+v[i-2];
        cout << cok(s,v[x-1]) << "\n";
    }
}
