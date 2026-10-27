#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e5+5;
int st[17][p],st2[17][p];
int a[p];
int n;

void build(){
	for(int i=1;i<=n;i++) st[0][i]=a[i];
	for(int j=1;j<=16;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[j][i]=__gcd(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
}
int find(int l, int r){
	int k=__lg(r-l+1);
	return __gcd(st[k][l],st[k][r-(1<<k)+1]);
}

int sol,t;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	build();
	unordered_map<int,int> mp;
	for(int i = 1; i <= n; i++){
		int l=i,r=n+1,id=i,x=a[i];
		while(1)
		{
			while(r - l > 1){
				int mid=(l+r)/2;
				if(find(i,mid)<x) r=mid;
				else l=mid;
			}
			if(r==n+1){
				mp[find(i,l)]+=l-id+1;break;
			}
			mp[find(i,l)]+=l-id+1;
			x=find(i,l+1);
			id=l+1;
			l++;r=n+1;
		}
	}

	cin >> t;
	while(t--){
		int k; cin>> k;
		cout << mp[k] << "\n";
	}
	return 0;
}
