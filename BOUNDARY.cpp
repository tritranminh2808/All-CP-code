#include <bits/stdc++.h>
#define int long long
using namespace std;
long long sol=0;
const int p=1e5+5;
int f[p][2];
signed main()
{
	freopen("boundary.inp","r",stdin);
	freopen("boundary.out","w",stdout);
	int n;cin >>n;
	vector < pair < int , int > > v(n);
	for(int i=0;i<n;i++)	cin >> v[i].first >> v[i].second;
	f[0][1]=v[0].first;
	f[0][0]=v[0].second;
//	if(v[0].first < v[0].second) swap(v[0].first,v[0].second);
	sol=max(f[0][0],f[0][1]);
	for(int i=1;i<n;i++){
		f[i][0]+=max(f[i-1][0]+abs(v[i-1].first-v[i].first)+v[i].second,f[i-1][1]+abs(v[i-1].second-v[i].first)+v[i].second);
		f[i][1]+=max(f[i-1][0]+abs(v[i-1].first-v[i].second)+v[i].first,f[i-1][1]+abs(v[i-1].second-v[i].second)+v[i].first);
//		cout << f[i][0] << " " << f[i][1] << "\n"; 
 //		if(f[i][1]>f[i][0]) swap (v[i].first,v[i].second);
	//	sol=max(f[i][0],f[i][1]);
	}
	cout << max(f[n-1][0],f[n-1][1]);;
	return 0;
}
