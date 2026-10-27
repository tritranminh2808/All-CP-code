#include <bits/stdc++.h>
using namespace std;
const int p=1001,mod=123456789;
int f[p][p],f2[p][p];
int main(){
	freopen("brackets.inp","r",stdin);
	freopen("brackets.out","w",stdout);
	int n,k; cin >> n >> k;
	
	f[0][0]=1,f2[0][0]=1;
	for(int i=1;i<=k;i++) {
		f[0][i]=0;f2[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			f[i][j]=0;
			if(j>0&&j<k) f[i][j]=(f[i][j]+f[i-1][j-1]+f[i-1][j+1])%mod;
			else if(j==0) f[i][j]=(f[i][j]+f[i-1][j+1])%mod;
			else if(j==k) f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
		//	if(j<k) f[i][j]=(f[i][j]+f[i-1][j+1])%mod;
		
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k-1;j++){
			f2[i][j]=0;
			if(j>0&&j<k) f2[i][j]=(f2[i][j]+f2[i-1][j-1]+f2[i-1][j+1])%mod;
			else if(j==0) f2[i][j]=(f2[i][j]+f2[i-1][j+1])%mod;
			else if(j==k) f2[i][j]=(f2[i][j]+f2[i-1][j-1])%mod;
		//	if(j<k) f2[i][j]=(f2[i][j]+f2[i-1][j+1])%mod;
		}
	}
	cout << (f[n][0]-f2[n][0]+mod)%mod;
	return 0;
}
