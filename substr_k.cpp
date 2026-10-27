#include <bits/stdc++.h>
// #define int long long
using ll= long long;
using namespace std;
const ll mod=1e9+7, mod2=1e9+9;
ll power[1000005],power2[1000005],hashT[1000005],hashT2[1000005];
int k,n;
int start=0;
bool check(int mid){
	// unordered_map<ll,int> mp;
    vector <ll > v;
	bool cc=0;
    ll sech=0,sech2=0;
	for(int i=1;i<=n-mid+1;i++){
		ll kk=(hashT[i+mid-1]-hashT[i-1]*power[mid])%mod;
		if(kk<0) kk+=mod;
        ll kk2=(hashT2[i+mid-1]-hashT2[i-1]*power2[mid])%mod2;
		if(kk2<0) kk2+=mod2;
        kk=(kk*257+kk2)%mod;
		v.push_back(kk);
	}
    sort(v.begin(),v.end());
    int cnt=1;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) cnt++;
        else cnt=1;
        if(cnt>=k){
            cc=1;
            sech=v[i];
            break;
        }
    }
	if(!cc) return false;
	for(int i=1;i<=n-mid+1;i++){
        ll kk=(hashT[i+mid-1]-hashT[i-1]*power[mid])%mod;
		if(kk<0) kk+=mod;
        ll kk2=(hashT2[i+mid-1]-hashT2[i-1]*power2[mid])%mod2;
		if(kk2<0) kk2+=mod2;
         kk=(kk*257+kk2)%mod;
        if(kk==sech){
            start=i;
            break;
        }
    }
	return true;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// int q; cin >> n;
	const int c=311,c2=311;
	power[0] = 1;
	power2[0]=1;
	for(int i = 1; i <= 1e6; i++){
        power[i] = power[i - 1] * c % mod;
	    power2[i] = power2[i - 1] * c2 % mod2;
    }
	string a; 
	cin >> a;
	cin >> k;
    // cout << k;
    n=a.length();
	a="!"+a;
    
	for (int i = 1; i <= n; i++) {
        hashT[i] = (hashT[i - 1] * c + a[i]  + 1) % mod;
	    hashT2[i] = (hashT2[i - 1] * c2 + a[i] + 1) % mod2;
    }
	int l=1,r=n,sol=0;
	while(l<=r){
		int mid=(l+r)/2;
        // cout << mid << "\n";
		if(check(mid)) {
			sol=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
    // cout << start << " ";
    for(int i=start;i<=start+sol-1;i++) cout << a[i];
	return 0;
}