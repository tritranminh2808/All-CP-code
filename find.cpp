#include <bits/stdc++.h>
#define int long long
using namespace std;
int pre[10000005];
int ans[10000005];
const int mod=1e9+7,base=547;
int power[10000005],hasht[10000005];
signed main(){
	power[0]=1;
	for(int i=1;i<=10000000;i++) power[i]=power[i-1]*base%mod;
	string s;
	cin >> s;
	int n=s.length();
	s=' '+s;
	for(int i=1;i<=n;i++) hasht[i]=(hasht[i-1]*base+s[i]+1)%mod;
	int l=1,r=n/2;
	int sol=0;
	int res=1;
	while(l<=r){
		int mid=(l+r)/2;
		int c=(hasht[mid]-hasht[0]*power[mid])%mod;
		bool sech=0;int kk=0;
		if(c<0) c+=mod;
		for(int i=mid+1;i<=n-mid+1;i++){
			int k=(hasht[i+mid-1]-hasht[i-1]*power[mid])%mod;
			if(k<0) k+=mod;
			if(k==c){
				sech=1;
				kk=i;
				break;
			}
		}
		if(sech==0) r=mid-1;
		else{
			sol=mid;
			res=kk;
			l=mid+1;
		}
	}
	cout << sol << " " << res;
	return 0;
}
