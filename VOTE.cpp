#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("VOTE.INP","r+",stdin);
	freopen("VOTE.OUT","w+",stdout);
	int n; cin>> n;
	char a[n][n]; for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin >> a[i][j];
	}
	int b[n];
	int max=-9999;
	for(int i=0;i<n;i++){
		int k=0;
		for(int j=0;j<n;j++){
			if(a[j][i]=='X')  k++;
		}
		b[i]=k;
		if(k>max) max=k;
	}
	int p=0;
	for(int i=0;i<n;i++){
		if (b[i]==max) p++;
	}
	cout << p << " " << max << "\n";
	for(int i=0;i<n;i++){
		if (b[i]==max) cout << i+1 << " ";
	}
	return 0;
}
