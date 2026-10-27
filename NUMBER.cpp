#include <bits/stdc++.h>
using namespace std;
pair <int, int> f[3005][3005];
int main() {
	freopen("number.inp","r",stdin);
	freopen("number.out","w",stdout);
	string lcs;
    string a, b;
    cin >> a >> b;
    int n=a.length(),m=b.length();
    for(int i=0;i<=m;i++) f[i][n]=make_pair(0,'!');
	for(int i=0;i<=n;i++) f[m][i]= make_pair(0,'!');
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;--j){
			if(a[i]==b[j]) f[i][j]=make_pair(f[i+1][j+1].first+1,a[i]);
			else f[i][j]=max(f[i+1][j],f[i][j+1]);
		}
	}
	pair <int, int> maxx=make_pair(0,'!');
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[i][j].second!='!') maxx=max(maxx,f[i][j]);
		}
	}
	if(maxx.first==0){
		cout << 0; return 0;
	}
	char c=maxx.second;
	int i=0,j=0;
	while(1){
		cout << c;
		while(a[i]!=c) i++;
		while(b[j]!=c) j++;
		i++;j++;
		if(f[i][j].first==0) break;
		c=f[i][j].second;
	}
    return 0;
}
