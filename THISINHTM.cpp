#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("THISINHTM.INP","r+",stdin);
	freopen("THISINHTM.OUT","w+",stdout);
	long long maxn=-1;
	int n;cin >> n;int a[n];for(int i=0;i<n;i++){
		cin >> a[i];maxn=max(maxn,a[i]);
	}int s=0;

	for(int i=0;i<n;i++){
		if(a[i]+20>=maxn){
			s++;
		}
	}cout << s;
	return 0;
}
