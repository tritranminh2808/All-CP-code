#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int spf[1000005];
void txl_spf(){
	for(int i=2;i<=1000000;i++){
		if(spf[i]) continue;
		for(int j=i;j<=1000000;j+=i) spf[j]=i;
	}
}
int gt[2000005];
int po(int n, int k){
    if(k==0) return 1;
    if(k==1) return n%mod;
    int tmp=po(n,k/2);
    tmp=(tmp*tmp)%mod;
    if(k%2==1) tmp=(tmp*n)%mod;
    return tmp;
}
int C(int k, int n){
    if(n<k) return 0;
    return (gt[n]*po(gt[k],mod-2)%mod*po(gt[n-k],mod-2)%mod)%mod;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    txl_spf();
    gt[0]=1;
    for(int i=1;i<=2000000;i++) gt[i]=gt[i-1]*i%mod;
	int t; cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;
        int sol=1;
        while(x>1){
            int cnt=0,p=spf[x];
            while(x%p==0){
                x/=p;
                cnt++;
            }
            sol*=C(cnt,cnt+y-1);
            sol%=mod;

        }
        sol*=po(2,y-1);
        sol%=mod;
        cout << sol << "\n";

	}
	return 0;
}
