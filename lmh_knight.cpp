#include <bits/stdc++.h>
using namespace std;
const int p=1e3+5;
char a[p][p];
bool vst[p][p];
int n,m;
int cnt=0;
void dfs(int i,int j){
	if(vst[i][j]) return;
	vst[i][j]=1;
	cnt++;
	int dr[8]={2,2,1,1,-1,-1,-2,-2},dc[8]={1,-1,2,-2,2,-2,1,-1};
	for(int k=0;k<8;k++){
		int newx=i+dr[k],newy=j+dc[k];
		if(newx>=0&&newx<n&&newy>=0&&newy<m&&a[newx][newy]=='.')dfs(newx,newy);
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
			if(a[i][j]=='.'&&!vst[i][j]){
				cnt=0;
				dfs(i,j);
				sol=max(sol,cnt);
//				dfs(i,j);
			}
		}
	}
	cout << sol;
	return 0;
}
