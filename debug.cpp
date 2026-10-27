#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[305][305],b[305][305];
const int mod=1e9+7,c=257;
int hash1[305][305],hash2[305][305];
int power[10000005];
int n,m;
bool check(int e){
//	cout << e << "::\n";
	for(int i=1;i<=n-e+1;i++){
		for(int j=1;j<=m-e+1;j++){
//			cout << i << " " << j << ":";
			bool sech=0;
			for(int x=0;x<=e/2;x++){
				int dong1=i+x,dong2=i+e-1-x;
				int k1=(hash1[dong1][j+e-1]-hash1[dong1][j-1]*power[e])%mod;
				int k2=(hash2[dong2][m-j+1]-hash2[dong2][m-j-e+1]*power[e])%mod;
//				cout << x << " " << j << " " << j+e-1 << " "<< m-j-e+2 << " " << m-j+1  << "|";
				if(k1<0) k1+=mod;
				if(k2<0) k2+=mod;
				if(k1!=k2) {
					sech=1;
					break;
				}
			}
			if(sech==0) return true;
//			cout << "\n";
		}
	}
	return false;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	power[0]=1;
	for(int i=1;i<=1000000;i++) power[i]=power[i-1]*c%mod;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) hash1[i][j]=(hash1[i][j-1]*c+a[i][j]+1)%mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++) b[i][m-j]=a[i][j+1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) hash2[i][j]=(hash2[i][j-1]*c+b[i][j]+1)%mod;
	}
	int e=min(n,m);
	while(e>1){
		if(check(e)){
			cout <<e ;
			return 0;
		}
		e--;
	}
	cout << -1;
	return 0;
}
