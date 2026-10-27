#include <bits/stdc++.h>
//#define int long long
using namespace std;
int stmin[23][1000005],stmax[23][1000005];
int a[1000005];
int n;
void build(){
	for(int i=0;i<=n;i++) {
		stmin[0][i]=a[i];
		stmax[0][i]=a[i];
	}
	for(int i=1;i<=21;i++){
		for(int j=1;j<=n;j++){
			stmin[i][j]=min(stmin[i-1][j],stmin[i-1][j+(1<<(i-1))]);
			stmax[i][j]=max(stmax[i-1][j],stmax[i-1][j+(1<<(i-1))]);
		}
	}
}
int findmin(int l,int r){
	int k1=__lg(r-l+1);
	return min(stmin[k1][l],stmin[k1][r-(1<<k1)+1]);
}
int findmax(int l, int r){
	int k1=__lg(r-l+1);
	return max(stmax[k1][l],stmax[k1][r-(1<<k1)+1]);
}
int sol=-878787887;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("bowling.inp","r",stdin);
	freopen("bowling.out","w",stdout);
	int k ; cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	build();
	for(int i=1;i<=n;i++) sol=max(sol,findmax(max(i-k,1),min(i+k,n))-findmin(max(i-k,1),min(i+k,n)));
	cout << sol;
//	cout << findmin(1,n) << " " << findmax(1,n);
	return 0;
}
