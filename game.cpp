#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int f[5005][5005];
int encode(int n,int m, int k){
	return (n*5000+m)*5000+k;
}
unordered_map<int, int > mp;
int cook(int n,  int m, int k){
	m=min(n,m);
	k=min(n,k);
	if(n<k||m<0||k<0) return 0;
	if(n==0) return 1;
	int x=encode(n,m,k);
	auto it=mp.insert({x,(int)0});
	if(it.second) it.first->second =(cook(n,m,k-1)+cook(n-k,m-1,k))%mod;
	return it.first-> second;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("game.inp","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,k; cin >> n >> m >> k;
	for(int i=0;i<=m;i++) f[i][0]=1;
	for(int i=0;i<=k;i++) f[1][i]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) {
			f[i][j]=f[i-1][j];
			if(j>=i) f[i][j]+=f[i][j-i];
			if(j>=i+k) f[i][j]-=f[i-1][j-i-k];
			f[i][j]%=mod;
//			f[i][j]=f[i-1][j]+f[i][j-i]+ f[i-1][j-i-k];
			
		}
	}
	cout << (f[m][n] + mod)%mod;
	return 0;
}
