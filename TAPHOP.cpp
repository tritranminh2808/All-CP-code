#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int chck[p];
int res;
int main ()
{
	freopen("TAPHOP.INP","r",stdin);
	freopen("TAPHOP.OUT","w",stdout);
	int n,m;cin >> n >> m;
	int a[n],b[m];
	for(int i=0;i<n;i++)	{
		cin >> a[i];
		chck[a[i]]++;
	}
	for(int i=0;i<m;i++) {
		cin >> b[i];
		chck[b[i]]++;
	}
	
	for(int i=0;i<p;i++)	if(chck[i]==2) res++;
	cout << res << "\n";
	for(int i=0;i<p;i++)	if(chck[i]==2) cout << i << "\n";
	return 0;
}
