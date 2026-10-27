#include <bits/stdc++.h>
#define int long long 
using namespace std;
using ull = long long;
//const int mod = 1e9+7;
ull gt[1000001];
void tienxuli(int mod){
	gt[0]=1;
	gt[1]=1;
	for(int i=2;i<1000001;++i){
		gt[i]=(gt[i-1]*(i%mod))%mod;
	}
}
ull mul(ull a, ull b, ull m){
	if(b==0) return 0;
	if(b==1) return a%m;
	ull t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
ull power(ull a,ull b, ull m) {
    if (b == 0) return 1;

    ull half = power(a, b/2, m);
   
    if (b%2==0) return mul(half,half,m);
    else return mul(half,mul(half,a,m),m);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin >> t;
    while(t--){
    	int n,m,p;
	    cin >> n>>m>>p;
	    tienxuli(p);
	    n=n-m+1;
	    if(n<m-1) cout << "0\n";
	    else {
		    ull res=gt[n]*power(gt[m],p-2,p)%p;
			cout << res*power(gt[n-m],p-2,p)%p << "\n";
		}
	}
}

