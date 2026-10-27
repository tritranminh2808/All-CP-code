#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e4+5;
int a[p],b[p],pre1[p],pre2[p];
int n,m;
signed main(){
	freopen("seqpairs.inp","r",stdin);
	freopen("seqpairs.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);
	vector <int> v1,v2;
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		pre1[i]=pre1[i-1]+a[i];
		for(int j=1;j<=i;++j) v1.push_back(pre1[i]-pre1[j-1]);
	}
	unordered_map<int,int> mp;
	for(int i=1;i<=m;i++){
		 cin>> b[i];
		 pre2[i]=pre2[i-1]+b[i];
		 for(int j=1;j<=i;++j) {
		 	v2.push_back(pre2[i]-pre2[j-1]);
		 	mp[pre2[i]-pre2[j-1]]++;
		 }
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int sol=0;
	for(auto i:v1){
		if(binary_search(v2.begin(),v2.end(),i))sol+=mp[i];
	}
 	cout << sol;
	return 0;
}
