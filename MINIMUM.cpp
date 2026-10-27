#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e6+5;
int st[19][p],st2[19][p];
int a[p];
int n;

void build(){
	for(int i=1;i<=n;i++) st[0][i]=a[i];
	for(int j=1;j<=18;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
}
int find(int l, int r){
	int k=__lg(r-l+1);
	return min(st[k][l],st[k][r-(1<<k)+1]);
}

int sol,t;
signed main(){
	freopen("minimum.inp","r",stdin);
	freopen("minimum.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> n>>k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	build();
	for(int i=1;i<=n-k+1;i++){
		cout << find(i,i+k-1) << "\n";
	}
	return 0;
}
