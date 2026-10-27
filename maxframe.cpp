#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1005][1005];
int pre[1005][1005],col[1005][1005],row[1005][1005],arr[1000000],minnn[1000000],b[1000000];
signed main(){
	
	int m, n;
	cin >> n>> m;
	for(int i=1; i<=n; i++)
    {
    	for(int j=1; j<=m; j++)
	    {
	        cin>>a[i][j];
	        pre[i][j] = pre[i-1][j] + a[i][j];
	    }
	}

	
	long long mx = -999999999999999;
	for(int i=0; i<=n; i++)
	{
	    for(int j=i+2; j<=n; j++)
	    {
	        minnn[0] = 0;
	        b[1] = pre[j][1] - pre[i][1];
	        b[2] = pre[j][2] - pre[i][2];
	        minnn[1] = b[1];
	        mx = max(mx, b[1]+b[2]);
	        for(int x=3; x<=m; x++)
	        {
	            b[x] = pre[j][x] - pre[i][x];
	            minnn[x-1] = max(minnn[x-2]+a[i+1][x-1]+a[j][x-1], b[x-1]);
	            mx = max(mx, b[x] + minnn[x-1]);
	        }
	    }
	}
	cout<<mx;
}
