#include <bits/stdc++.h>
using namespace std;
int n,m;
bool a[505][505];
int pre[505][505];
int res[505][505];
int dx[2]={0,1},dy[2]={1,0};
bool vst[505][505];
bool check(int xi1,int yi1,int xi2,int yi2){
	return pre[xi2][yi2]-pre[xi2][yi1-1]-pre[xi1-1][yi2]+pre[xi1-1][yi1-1]==0;
}
int bfs(int u, int v){
	int sol=0;
	memset(vst,0,sizeof(vst));
	queue<pair <int, int > > q;
	q.push({u,v});
	while(!q.empty()){
		pair <int ,int >  p=q.front();
		q.pop();
		if(vst[p.first][p.second]) continue;
//		cout << p.first << " " << p.second << "\n";
		vst[p.first][p.second]=1;
		sol=max(sol,(p.first-u+1)*(p.second-v+1));
		for(int i=0;i<2;i++){
			int newx=p.first+dx[i],newy=p.second+dy[i];
			if(check(u,v,newx,newy)&&newx>=1&&newy>=1&&newx<=n&&newy<=m) q.push({newx,newy});
		}
	}
	return sol;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]) res[i][j]=0;
			else res[i][j]=bfs(i,j);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;j++) cout << res[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
