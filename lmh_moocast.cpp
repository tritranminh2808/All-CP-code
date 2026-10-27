#include <bits/stdc++.h>
#define int long long
using namespace std;
int n; 
int sol=1;
struct pl{
	int x,y,v;
};
pl a[20005];
long long kc(int x1, int y1, int x2, int y2){
	long long A=abs(x1-x2),B=abs(y1-y2);
	return A*A+B*B;
}
void bfs(pl u){
	queue<pl> q;
	map<pair <int, int > , bool> mp;
	q.push(u);
	mp[{u.x,u.y}]=1;
	int cnt=1;
	while(!q.empty()){
		pl p=q.front();
//		cout << p.x << " " << p.y << " " << p.v << " " << p.cnt << "\n";
		q.pop();
//		if(mp[{p.x,p.y}]) continue;	
		for(int i=1;i<=n;i++){
			if(!mp[{a[i].x,a[i].y}]&&kc(p.x,p.y,a[i].x,a[i].y)<=p.v*p.v) {
				q.push({a[i].x,a[i].y,a[i].v});
				mp[{a[i].x,a[i].y}]= 1;
				cnt++;
			}
		}
	}
	sol=max(sol,cnt);
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i].x >> a[i].y >> a[i].v;
//		a[i].cnt=1;
	}
//	bfs(a[1]);
	for(int i=1;i<=n;i++) bfs(a[i]);
	cout << sol;
	return 0;
}
