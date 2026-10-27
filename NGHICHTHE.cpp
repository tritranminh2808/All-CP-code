#include <bits/stdc++.h>
using namespace std;
const int p=1e7+5;
int r[p];
int main()
{
	freopen("NGHICHTHE.inp","r",stdin);
	freopen("NGHICHTHE.out","w",stdout);
	int n; cin >> n;
	int a[n];
	for (int i=0;i<n;i++) cin >> a[i];
	r[a[0]]=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++) if(a[j]>a[i]) r[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cout << r[i] << " ";
	}
	return 0;
}
