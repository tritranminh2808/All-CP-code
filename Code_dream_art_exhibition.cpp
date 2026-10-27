#include <bits/stdc++.h>
#define int long long
using namespace std;
const int pp=5e5+5;
int n,pre[pp],spre[pp];
pair <int, int > v[pp];
struct pl{
	int val,s,maxx,minn;
};
pl dp[2][pp];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> v[i].first >> v[i].second;
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++){
//		int x=v[i].second-v[i].first+v[i-1].first;
		pre[i]=pre[i-1]+v[i].second;
	}
	int maxx=0,cur=0,minn=1e18;
//	for(int i=1;i<=n;i++) cout << pre[i] << " ";
	for(int i=1;i<=n;i++){
		cur=max(cur,-pre[i-1]+v[i].first);
		maxx=max(maxx,pre[i]-v[i].first+cur);
	
	}
	cout << maxx ;
	return 0;
}
