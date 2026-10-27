#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,-1,1,0},dy[4]={1,0,0,-1};
bool a[1005][1005];
bool vst[1005][1005][5];
int n,m,xx,yy,x2,y2;
struct pl{
	int x,y,chck;
	string s;
};
void bfs(int u, int v){
	queue<pl> q;
//	string sss;
	q.push({u,v,4,""});
//	vst[u][v]=1;
	while(!q.empty()){
		pl p=q.front();
		q.pop();
		if(vst[p.x][p.y][p.chck])  continue;
		vst[p.x][p.y][p.chck]=1;
		if(p.x==x2&&p.y==y2){
			cout << p.s;
			exit(0);
		}
		for(int i=0;i<4;i++){
			int newx=p.x+dx[i],newy=p.y+dy[i];
			char c;
			if(i==0) c='E';
			if(i==1) c='N' ;
			if(i==2) c='S';
			if(i==3) c='W';
			if(!p.s.empty()&&c==p.s[p.s.length()-1]) continue;
			string ss=p.s+c;
			if(newx>=0&&newx<=n&&newy>=0&&newy<=m&&!a[newx][newy]) q.push({newx,newy,i,ss});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("lmh_input.inp","r",stdin);
    cin >> n >> m >> xx >> yy >> x2 >> y2;
    int u,v;
    while(cin >>u){
    	cin >> v;
    	a[u][v]=1;
	}
	bfs(xx,yy);
}
