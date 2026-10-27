#include <bits/stdc++.h>
#define int long long
using ll=long long;
using namespace std;
const int mod=1e9+7, mod2=1e9+9;
using ull=unsigned long long;
ull mul(ull a, ull b, ull m){
	if(b==0) return 0;
	ull t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
ll power[1000005],power2[1000005],hashT[1000005],hashT2[1000005];
signed main(){
	
	const int c=31,c2=37;
	power[0] = 1;
	power2[0]=1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	for(int i = 1; i <= 1e6; i++) power2[i] = power2[i - 1] * c2 % mod2;
	string a; string b;
	int t; 
	cin >> b; 
	int lenb=b.length();
	b=" "+b;
	for (int i = 1; i <= lenb; i++) hashT[i] = (hashT[i - 1] * c + b[i] - 'a' + 1) % mod;
	for (int i = 1; i <= lenb; i++) hashT2[i] = (hashT2[i - 1] * c2 + b[i] - 'a' + 1) % mod2;
	cin >> t;
	while(t--){
        string a;
		cin >> a;
        int lena=a.length();
        a=" "+a;
        int hashP=0,hashP2=0;
        for(int i=1;i<=lena;++i)  hashP = (hashP * c + a[i] - 'a' + 1)%mod;
        for(int i=1;i<=lena;++i)  hashP2 = (hashP2 * c2 + a[i] - 'a' + 1)%mod2;
        
        bool chck=0;
        int cnt=0;
        for(int i=1;i<=lenb-lena+1;++i){
            int k=(hashT[i+lena-1]-hashT[i-1]*power[lena])%mod;
            int k2=(hashT2[i+lena-1]-hashT2[i-1]*power2[lena])%mod2;
            if(k<0) k += mod;
            if(k2<0) k2+=mod2;
            if(hashP==k&&hashP2==k2)cnt++;
            //	cout << hashP <<" "<< k << endl;
        }
        cout << cnt <<"\n";
    }
	return 0;
}

