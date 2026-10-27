#include <bits/stdc++.h>
using namespace std;
vector <int> mp[1000005];
int m,n;
int par[1000005];
int a[1000005];
int encode(int i,int j){
	return i*n+j;
}
void decode (int x,int& i, int& j){
	i=x/n;
	j=x%n;
}
int find(int u){
	if(par[u]==u) return u;
	return par[u]=find(par[u]);
}
int sech=0, res=0;
void cook(int h){
	for(int i:mp[h]){
		++sech;
		par[i]=i;
	}
	int X[4]={0,0,-1,1};
	int Y[4]={1,-1,0,0};
	for(int x:mp[h]){
		int i,j,p,q;
		decode(x,i,j);
		for(int d=0;d<4;++d){
			p=i+X[d];q=j+Y[d];
			if(p<0||p>=m||q<0||q>=n)continue;		
			int y=encode(p,q);
			if(a[y]<h) continue;
			int k1=find(x);
			int k2=find(y);
			if(k1!=k2){
				par[k1]=k2;
				--sech;
			}
		}
	}
}
int main(){
	freopen("islands.inp","r",stdin);
	freopen("islands.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	 cin >> m >> n;
	 int maxpi=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)	{
			int x=encode(i,j);
			int h; cin >> h;
			maxpi=max(maxpi,h);
			mp[h].push_back(x);
			a[x]=h;
	}
	}
	for(int h=maxpi+1;h>0;h--){
		cook(h);
		if(sech>res) res=sech;
//		cout << h << " " << sech << endl;
	}
	cout << res;
	return 0;
}


