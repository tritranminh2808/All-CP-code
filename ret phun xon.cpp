#include <bits/stdc++.h>
#define int long long
using namespace std;
int c=31;
const int mod=1e9+7;
int hash1[100005], hash2[100005],power[1000005];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	power[0]=1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	string a;
	cin >> a;
	int n=a.length();
	a=' '+a;
	for(int i=1;i<=n;i++) hash1[i]=(hash1[i-1]*c+a[i]-'a'+1)%mod;
	for(int i=1;i<=n;i++){
		int l=1,r=n-i+1;
		while(l<=r){
			int mid=(l+r)/2;
			int k=(hash1[1+mid-1]-hash1[0]*power[mid])%mod,k2=(hash1[i+mid-1]-hash1[i-1]*power[mid])%mod;
			if(k<0) k+=mod;
			if(k2<0) k2+=mod;
			if(k==k2) l=mid+1;
			else r=mid-1;
		}
		cout << l-1 << " ";
	}
	
	return 0;
}
