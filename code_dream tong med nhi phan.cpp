#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int gt[200005];
int cok(int n,int k){
	if(k==1) return n;
	if(k==0) return 1;
	int tmp=cok(n,k/2);
	tmp=(tmp*tmp)%mod;
	if(k%2==1) tmp=(tmp*n)%mod;
	return tmp;
}
int cal(int k, int n){
	if(n<k) return 0;
	return (gt[n]%mod*cok(gt[n-k],mod-2)%mod*cok(gt[k],mod-2)%mod+mod)%mod;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	gt[0]=1;
	for(int i=1;i<=200000;i++) gt[i]=(gt[i-1]*i)%mod;
//	cout << cal(3 ,5);return 0;
	int t; cin>> t;
	
	while(t--){
		int n,k; cin >> n >> k;
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			int u; cin >> u;
			if(u) cnt1++;
			else cnt0++;
		}
//		cout << cnt0 << " " << cnt1 << "\n";
		int sol=0;
		for(int i=(k+1)/2;i<=k;i++){
			sol=(sol+cal(i,cnt0)*cal(k-i,cnt1)+mod)%mod;
		}
		cout << (cal(k,n)-sol+mod)%mod << "\n";
	}
}
