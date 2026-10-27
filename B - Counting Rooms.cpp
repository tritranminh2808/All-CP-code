#include <bits/stdc++.h>
using namespace std;
const int p=1e3+5;
char a[p][p];
bool vst[p][p];
int n,m;
void dfs(int i,int j){
	vst[i][j]=1;
	if(vst[i-1][j]==0&&i>=1&&a[i-1][j]==a[i][j]){
		dfs(i-1,j);
	}
	if(vst[i][j+1]==0&&j+1<m&&a[i][j+1]==a[i][j]){
		dfs(i,j+1);
	}
	if(vst[i][j-1]==0&&j>=1&&a[i][j-1]==a[i][j]){
		dfs(i,j-1);
	}
	if(vst[i+1][j]==0&&i+1<n&&a[i+1][j]==a[i][j]){
		dfs(i+1,j);
	}
}

int sol=0;
int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++){
			cin >>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='.'&&vst[i][j]==0){
				sol++;
				dfs(i,j);
			}
		}
	}
	cout << sol;
	return 0;
}
