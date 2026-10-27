#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("SortMT.inp","r",stdin);
	freopen("SortMT.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,x;
	cin >> n >> m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)	cin  >> a[i][j];
	}
	int maxx = a[0][0], minn = a[0][0];
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++)	{
			maxx=max(maxx,a[i][j]);
			minn=min(minn,a[i][j]);
		}
	}
	cout << maxx << " " << minn << "\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			for(int k=j+1;k<m;k++){
				if (a[i][j]>a[i][k])  swap(a[i][j],a[i][k]);
				
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
