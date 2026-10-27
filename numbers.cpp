#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[10][105],f[10][105],dp2[105][11][2];
bool vis[105][11][2];
const int mod=1e9+7;
int cac(int p, int l, int t, string s) {
    if(p==s.size()) return 1;
    if(vis[p][l][t]) return dp2[p][l][t]%mod;
    vis[p][l][t]=1;
    int r=0;
    int lim=t? s[p]-'0':9;
    for (int i=l;i<=lim;i++) {
        r=(r+cac(p+1,i,t&&(i==lim),s))%mod;
    }
    return dp2[p][l][t]=r;
}
int cal(string s){
	for(int i=0;i<10;i++){
		for(int j=0;j<=100;j++) f[i][j]=0;
	}
	int n=s.length();
	int sech=0;
	for(int j=1;j<=n-1;j++){
		for(int i=1;i<=9;i++) sech=(sech+dp[i][j])%mod;
	}
	for(int i=0;i<n;i++) {
		if(s[i]=='0') return sech%mod;
	}
	int x=0;
	int f0=s[0]-'0';
    for (int i=1;i<f0;i++) x=(x+cac(1,i,0,s))%mod;
    x=(x+cac(1,f0,1,s))%mod;
	return (x+sech)%mod;
}
signed main(){
	for(int i=1;i<=9;i++) dp[i][1]=1;
	for(int i=2;i<=100;i++){
		for(int j=1;j<=9;j++){
			for(int k=1;k<=j;k++) dp[j][i]=(dp[j][i]+dp[k][i-1])%mod;
		}
	}
	string a,b;
	cin >> a;
	cin >> b;
	int sol=((cal(b)-cal(a))%mod + mod)%mod;
	bool sech=0;
	for(int i=0;i<a.length()-1;i++) {
		if(a[i]>a[i+1]){
			sech=1;
			break;
		}
	}
	if(sech==0) sol++;
	cout << sol%mod;
}
