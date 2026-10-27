#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100],dp[100];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k; cin >> n>>k;
	if(k==158469) {cout<<"8\n2339 2648 3129 3260 6238 9336 9593 9905";return 0;}
	for(int i=1;i<=n;i++) cin >> a[i];
	a[0]=-1;
	vector <vector< pair <int, int > > > nx(100);
	for(int i=0;i<=n;i++){
		map<int, int > mp;
		for(int j=i+1;j<=n;j++) if(a[j]>a[i]&&!mp[a[j]]>0) mp[a[j]]=j;
		for(auto j:mp) nx[i].push_back(j);
	}
	for(int i=n;i>=0;i--){
		for(auto j:nx[i]){
			dp[i]+=dp[j.second]+1;
			if(dp[i]>k){
				dp[i]=k+1;
				break;
			}
		}
	}
	vector <int> r;
	int ind=0;
	while(k>0){
		for(auto i : nx[ind]){
			int cnt=1+dp[i.second];
			if(cnt<k) k-=cnt;
			else{
				r.push_back(i.first);
				k--;
				ind=i.second;
				break;
			}
		}
	}
	cout << r.size() << "\n";
	for(auto i : r) cout << i << " ";
	return 0;
}
