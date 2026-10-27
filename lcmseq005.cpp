#include <bits/stdc++.h>
#define ll unsigned long long
#define ld long double
using namespace std;
// 
const ll maxn =355;
const ll mod = 1e9+7; 
bool prime(ll x){
	for (ll i=2;i<=sqrt(x);i++) {
		if (x%i==0) return false;
	}
	return true;
}
ll f[maxn];
ll n;
int main() {
     freopen("lcmseq005.inp","r",stdin);
     freopen("lcmseq005.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> pr;
    f[0]=1;
    f[1]=1;
    for (ll i=2;i<=350;i++) if (prime(i)) pr.push_back(i);
    for (auto p:pr) {
    	for (ll i=350;i>=p;i--) {
    		ll t=p;
    		while (t<=i){
    			f[i]=max(f[i],f[i-t]*t);
    			t*=p;
    		}
    	}
    }
    cin >>n;
    cout <<*max_element(f+1,f+1+n);
    return 0;
}
