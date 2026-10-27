#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> ST((const int)4e6+5,0);
void update(int id , int l, int r, int u, int v){
	if(u>r||u<l) return;
	if(l==r) {
		ST[id]=v;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	ST[id]=max(ST[id*2],ST[id*2+1]);
}
int find(int id , int l, int r, int u, int v){
	if(u>r||v<l) return 0;
	if(u<=l && r<=v) return ST[id];
	int mid=(l+r)/2;
	int min1=find(id*2,l,mid,u,v);
	int min2=find(id*2+1,mid+1,r,u,v);
	return max(min1,min2);
}
struct sech{
	int v,w,ind;
};
int dp[1000005];
bool cmp(sech a, sech b){
	if(a.v==b.v) return a.ind > b.ind;
	return a.v<b.v;
}
bool cmpx(sech a, sech b){
	return a.ind<b.ind;
}
sech a[1000005];
signed main(){
	freopen("is.inp","r",stdin);
	freopen("is.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i].v;
	for(int i=1;i<=n;i++) {
		cin >> a[i].w;
		a[i].ind=i;
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) cout << a[i].v << " "<< a[i].w << " " << a[i].ind << "\n";
	for(int i=1;i<=n;i++){
//		cout << a[i].first << " " << a[i].second << endl;
		dp[a[i].ind]=find(1,1,n,1,a[i].ind-1)+a[i].w;
//		cout << a[i].w
		update(1,1,n,a[i].ind,dp[a[i].ind]);
	}
	int maxx=-9219219,end=1000000007;
	deque<int> q;
	sort(a+1,a+n+1,cmpx);
	for(int i=1;i<=n;i++)maxx=max(maxx,dp[i]);
	for(int i=n;i>=1;i--){
		if(dp[i]==maxx&&a[i].v<end){
			q.push_front(i);
			maxx-=a[i].w;
			end=a[i].v;
		}
	}
	cout << q.size () << "\n";
	for(auto i: q) cout <<i << " ";
	return 0;
	
}
