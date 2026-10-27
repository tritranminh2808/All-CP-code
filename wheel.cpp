#include <bits/stdc++.h>
#define int long long
using namespace std;
int st[47][100005],dp[47][100005],a[100005];
int n;
void build(){
	for(int i=0;i<n;i++) {
		st[0][i]=a[(i+1)%n];
		dp[0][i]=a[(i+1)%n];
	}
	for(int i=1;i<=46;i++){
		for(int j=0;j<n;j++){
			st[i][j]=st[i-1][j]+st[i-1][(j+(1<<(i-1)))%n];
			dp[i][j]=max(dp[i-1][j],dp[i-1][(j+(1<<(i-1)))%n]+st[i-1][j]);
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>> n;
	for(int i=0;i<n;i++) cin >> a[i];
	build();
	int cur=n-1,next=n-1;
	int q;cin>>q;
	while(q--){
		next=cur;
		int x;cin>> x;
		int sol=0;
		for(int i=46;i>=0;--i){
			if(dp[i][next]<x){
				sol+=1<<i;
				x-=st[i][next];
				next=(next+(1<<i))%n;
			}
		}
		cout << sol+1 << "\n";
		next++;
		next%=n;
		cur=next;
	}
	return 0;
}
