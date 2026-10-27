#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int vst[1005][1005];
int n,m;
int sol=12345678;
struct pl{
	int x,y,cnt;
};
void bfs(){
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++) vst[i][j]=INT_MAX;
	}
	deque<pl> q;
	for(int i=1;i<=n;i++) q.push_back({i,1,1});
//	map<pair<int, pair <int, int > >,bool> vst;
	while(!q.empty()){
		pl c=q.front();
		q.pop_front();
		if(c.cnt>=vst[c.x][c.y]) continue;
		vst[c.x][c.y]=c.cnt;
//		cout << c.x << " " << c.y << " " << c.cnt << "\n";
		if(c.y==m) {
			sol=min(sol,c.cnt);
			continue;
		}
		if(c.cnt>=sol) continue;
		if(c.x>1){
			if(a[c.x-1][c.y]!=a[c.x][c.y]) q.push_back({c.x-1,c.y,c.cnt+1});
			else q.push_front({c.x-1,c.y,c.cnt});
		}
		if(c.y>1){
			if(a[c.x][c.y-1]!=a[c.x][c.y]) q.push_back({c.x,c.y-1,c.cnt+1});
			else q.push_front({c.x,c.y-1,c.cnt});
		}
		if(c.y<m){
			if(a[c.x][c.y+1]!=a[c.x][c.y]) q.push_back({c.x,c.y+1,c.cnt+1});
			else q.push_front({c.x,c.y+1,c.cnt});
		}
		if(c.x<n){
			if(a[c.x+1][c.y]!=a[c.x][c.y]) q.push_back({c.x+1,c.y,c.cnt+1});
			else q.push_front({c.x+1,c.y,c.cnt});
		}
	}
	cout << sol;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	bfs();
	return 0;
}
