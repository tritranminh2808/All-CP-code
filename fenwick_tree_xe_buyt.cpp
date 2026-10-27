#include <bits/stdc++.h>
using namespace std;
int st[1000005];
void update(int i, int v){
	for(;i<=1000000;i+=i&-i) st[i]=max(st[i],v);
}
int find(int x){
	int s=0;
	for(int i=x;i>0;i-=i&-i) s=max(s,st[i]);
	return s;
}
struct pl{
	int x,y,val; 
};
pl v[200005];
unordered_map<int, int > newx,newy;
vector <int> b,c;
void nen(){
	sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=0;i<b.size();i++) newx[b[i]]=i+1;
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(int i=0;i<c.size();i++) newy[c[i]]=i+1;
    
}
int cnt[3000005];
int X,Y;
vector <pair <int, int > >  adj[100005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> X >> Y >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i].x >> v[i].y >> v[i].val;
        b.push_back(v[i].x);
        c.push_back(v[i].y);
    }
    nen();
    for(int i=1;i<=n;i++){
        v[i].x=newx[v[i].x];
        v[i].y=newy[v[i].y];
    }
    for(int i=1;i<=n;i++){
        adj[v[i].x].push_back({v[i].y,v[i].val});
    }
    int res=0;
    for(int i=1;i<=100000;i++){
        sort(adj[i].begin(),adj[i].end());
        for(auto j:adj[i]){
            int y=j.first,g=j.second;
            res=max(res,find(y)+g);
            update(y,find(y)+g);
        }
    }
    cout << res;
	return 0;
}
