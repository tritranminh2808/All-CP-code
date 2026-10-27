#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> b;
int n,m;
int x[200005],y[200005],w[200005];
unordered_map<int, int> newv;
void nen(){
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=0;i<b.size();i++) newv[b[i]]=i;
	for(int i=1;i<=n;i++){
		x[i]=newv[x[i]];
		y[i]=newv[y[i]];
	}
	m=newv[m];
}
struct pl{
	int start,val,id;
};
vector <pl> ed[200005];
int dp[200005];
int st[800005];
void update(int id,int l, int r, int u, int v){
	if(u<l||u>r) return;
	if(l==r) {
		st[id]=v;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	st[id]=min(st[id*2],st[id*2+1]);
}
int find(int id, int l, int r, int lf, int rt){
	if(lf>r||rt<l) return 1e18;
	if(lf<=l&&rt>=r) return st[id];
	int mid=(l+r)/2;
	return min(find(id*2,l,mid,lf,rt),find(id*2+1,mid+1,r,lf,rt));
}
int preid[200005],prenode[200005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	b.push_back(m);
	b.push_back(0);
	for(int i=0;i<=800000;i++) st[i]=1e18;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i] >> w[i];
		b.push_back(x[i]);
		b.push_back(y[i]);
	}
	nen();
	for(int i=1;i<=n;i++) ed[y[i]].push_back({x[i],w[i],i});
	int maxx=b.size()-1;
	dp[0]=0;
	update(1,0,maxx,0,0);
	for(int i=0;i<b.size();i++) {
		preid[i]=-1;
		prenode[i]=-1;
	}
	for(int i=1;i<=m;i++){
		dp[i]=1e18;
		for(auto j:ed[i]) {
			if(find(1,0,maxx,j.start,i-1)+j.val<dp[i]){
				dp[i]=find(1,0,maxx,j.start,i-1)+j.val;
				for(int k=j.start;k<i;++k){
			        if(dp[k]==find(1,0,maxx,j.start,i-1)){
			            prenode[i]=k;
			            break;
			        }
			    }
				preid[i]=j.id;
			}
		}
		update(1,0,maxx,i,dp[i]);
	}
	cout << dp[m] << "\n";
	vector <int> truy;
	int k=m;
	while(k!=0){
		truy.push_back(preid[k]);
		k=prenode[k];
	}
	reverse(truy.begin(),truy.end());
	for(auto i:truy) cout << i << " ";
	return 0;
}
