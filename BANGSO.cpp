
#include <bits/stdc++.h>
using namespace std;
const int p=1e3+5;
int a[p][p];
bool vst[p][p];
int n,m;
int sol=0;
int maxx=-1e5;
void dfs(int i,int j,int& sz,bool& check){
	vst[i][j]=1;
	if(i>=1&&vst[i-1][j]==0&&a[i-1][j]==a[i][j]){
		sz++;
		if(sz>=2&&check==0) {
			sol++;
			check=1;
		}
		maxx=max(maxx,sz);
		dfs(i-1,j,sz,check);
	}
	if(j+1<m&&vst[i][j+1]==0&&a[i][j+1]==a[i][j]){
		sz++;
		if(sz>=2&&check==0) {
			sol++;
			check=1;
		}
		maxx=max(maxx,sz);
		dfs(i,j+1,sz,check);
	}
	if(j>=1&&vst[i][j-1]==0&&a[i][j-1]==a[i][j]){
		sz++;
		if(sz>=2&&check==0) {
			sol++;
			check=1;
		}
		maxx=max(maxx,sz);
		dfs(i,j-1,sz,check);
	}
	if(i+1<n&&vst[i+1][j]==0&&a[i+1][j]==a[i][j]){
		sz++;
		if(sz>=2&&check==0) {
			sol++;
			check=1;
		}
		maxx=max(maxx,sz);
		dfs(i+1,j,sz,check);
	}
	if(i>=1&&j>=1&&vst[i-1][j-1]==0&&a[i-1][j-1]==a[i][j]){
		sz++;
		if(sz>=2&&check==0) {
			sol++;
			check=1;
		}
		maxx=max(maxx,sz);
		dfs(i-1,j-1,sz,check);
	}
	if(i>=1&&j+1<m&&vst[i-1][j+1]==0&&a[i-1][j+1]==a[i][j]){
		sz++;
		if(sz>=2&&check==0) {
			sol++;
			check=1;
		}
		maxx=max(maxx,sz);
		dfs(i-1,j+1,sz,check);
	}
	if(j>=1&&i+1<n&&vst[i+1][j-1]==0&&a[i+1][j-1]==a[i][j]){
		sz++;
		if(sz>=2&&check==0) {
			sol++;
			check=1;
		}
		maxx=max(maxx,sz);
		dfs(i+1,j-1,sz,check);
	}
	if(i+1<n&&j+1<m&&vst[i+1][j+1]==0&&a[i+1][j+1]==a[i][j]){
		sz++;
		if(sz>=2&&check==0) {
			sol++;
			check=1;
		}
		maxx=max(maxx,sz);
		dfs(i+1,j+1,sz,check);
	}
}


int main(){
//	freopen("BANGSO.inp","r",stdin);
//	freopen("BANGSO.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++){
			cin >>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vst[i][j]==0){
				//sol++;
				int sz=1;
				bool check=0;
				dfs(i,j,sz,check);
				maxx=max(maxx,sz);
			}
		}
	}
	
	cout << sol << "\n" << maxx;
	return 0;
}
