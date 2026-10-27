#include <bits/stdc++.h>
#define int long long
using namespace std;
char a[1005][1005];
int hashT[1005][1005];
int power[1000005];
int c=919;
const int mod=1e9+7;
signed main(){
	power[0]=1;
	for(int i=1;i<=1000000;i++) power[i]=power[i-1]*c%mod;
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--) hashT[i][j]=(hashT[i+1][j]*c+a[i][j]+1)%mod;
	}
	int sol=0;
	for(int s=1;s<n;s++){
		bool check=1;
		map<int,int> mp;
		for(int i=1;i<=m;i++){
			if(mp[hashT[s+1][i]]==1){
				check=0;
				break;
			}
			mp[hashT[s+1][i]]=1;
		}
		if(check==1) sol=s;
		else break;
	}
	cout << sol;
	return 0;
}
