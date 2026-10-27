#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e3+9;
int a[p][p];
bool vst[p][p];
int n,m;
int sol=0;
int maxx=0;
int x_1,y_1,x_2,y_2;
void  dfs(int i,int j,int& sz){
	vst[i][j]=1;
	if(i<1||j<1||i>n||j>m) return;
	if(vst[i-1][j]==0&&a[i-1][j]==1){
		sz++;
		x_1=min(x_1,i-1);
		y_1=min(y_1,j);
		x_2=max(x_2,i-1);
		y_2=max(y_2,j);
		dfs(i-1,j,sz);
	}
	if(vst[i][j+1]==0&&a[i][j+1]==1){
		sz++;
		x_1=min(x_1,i);
		y_1=min(y_1,j+1);
		x_2=max(x_2,i);
		y_2=max(y_2,j+1);
		dfs(i,j+1,sz);
	}
	if(vst[i][j-1]==0&&a[i][j-1]==1){
		sz++;
		x_1=min(x_1,i);
		y_1=min(y_1,j-1);
		x_2=max(x_2,i);
		y_2=max(y_2,j-1);
		dfs(i,j-1,sz);
	}
	if(vst[i+1][j]==0&&a[i+1][j]==1){
		sz++;
		x_1=min(x_1,i+1);
		y_1=min(y_1,j);
		x_2=max(x_2,i+1);
		y_2=max(y_2,j);
		dfs(i+1,j,sz);
	}
}
int pre[p][p];
signed main(){
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++){
			cin >>a[i][j];
			pre[i][j]=0;
		}
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++){
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1 ;j<=m;j++){
			if(vst[i][j]==0&& a[i][j]==1){
				//sol++;
				x_2=-1;y_2=-1;x_1=1010;y_1=1010;
				int sz=1;dfs(i,j,sz);
				
				int t1=pre[x_2][y_2]-pre[x_2][y_1-1]-pre[x_1-1][y_2]+pre[x_1-1][y_1-1]; 
				//cout << t1 << " " << sz <<endl;
				if(t1==(x_2-x_1+1)*(y_2-y_1+1)){
					int t2=pre[x_2+1][y_2+1]-pre[x_2+1][y_1-2]-pre[x_1-2][y_2+1]+pre[x_1-2][y_1-2];
					if(x_1!=1&&y_1!=1&&x_2!=n&&y_2!=m&&t2==t1) maxx=max(maxx,sz);
				}
			}
		}
	}
	cout << maxx;
	return 0;
}
