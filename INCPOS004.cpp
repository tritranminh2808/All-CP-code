#include <bits/stdc++.h>
using namespace std;
int t=0;
int main()
{
	freopen("INCPOS004.INP","r",stdin);
	freopen("INCPOS004.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k; cin >> n >> k;
	int a[n]; for(int i=0;i<n;i++) cin >> a[i];
	int l[k],r[k],x[k];
	for(int i=0;i<k;i++)cin >> l[i] >> r[i] >> x[i];
	for(int i=0;i<k;i++){
		int t=0;
		
		for(int j=l[i]-1;j<r[i];j++) a[j]+=x[i];
		for(int j=0;j<n-1;j++) if(a[j]>a[j+1])  t++;
		//cout << "\n";
		
		cout << t << "\n";
	}
	return 0;
}
