
#include <bits/stdc++.h>
using namespace std;
const int p=1e3+5;
int a[p][p];
bool vst[p][p];
int n,m;
bool check (int i, int j, int i2, int j2){
	for(int l=i;l<i2;l++){
		for(int r=j;r<j2;r++){
			if(a[l][r]==a[l+1][r]||a[l][r]==a[l][r+1]) return false;
		}
	}
	return true;
}
int sol=0;
int main(){

	cin >> n >> m;
	if(n==1){
		int aa[2][100005];
			for(int j=1;j<=m;j++) cin >> aa[1][j];
		
		int sol=-999;
		aa[1][0]=999;
		int dem=0;
		for(int i=1;i<=m;i++){
			if(aa[1][i]!=aa[1][i-1]) dem++;
			else dem=0;
			sol=max(sol,dem);
		}
		cout << sol;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int i2=i+1;i2<=n;i2++){
				for(int j2=j+1;j2<=m;j2++){
					if(check(i,j,i2,j2)) sol=max(sol,(i2-i+1)*(j2-j+1));
				}
			}
		}
	}
	cout << sol;
	return 0;
}
