#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int gtri; int lazy;
};
struct pl{
	int w,d,v;
};
struct rod{
	int wei,price;
};
node st [800005];
pl a[200005];
int n,b,m;
rod c[200005];
vector <int> nen;
void build(int id, int l, int r){
	if(l==r){
		st[id].gtri=-nen[l-1]*b;return;
	}
	int mid=(r+l)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].gtri=max(st[id*2].gtri,st[id*2+1].gtri);
}
void push(int crr){
	st[crr*2].gtri+=st[crr].lazy;
	st[crr*2+1].gtri+=st[crr].lazy;
	st[crr*2].lazy+=st[crr].lazy;
	st[crr*2+1].lazy+=st[crr].lazy;
	st[crr].lazy=0;
}
void update(int crr, int l, int r, int lf, int rt, int val){
	if(l>rt||r<lf) return ;
	if(l>=lf&&r<=rt){
		st[crr].gtri+=val;
		st[crr].lazy+=val;
		return ;
	}
	push(crr);
	int mid=(l+r)/2;
	update(crr*2,l,mid,lf,rt,val);
	update(crr*2+1,mid+1,r,lf,rt,val);
	st[crr].gtri=max(st[crr*2].gtri,st[crr*2+1].gtri);
}
int get(int crr, int l, int r, int lf, int rt){
	if(lf>r||rt<l) return -1e18;
	if(lf<=l&&r<=rt) return st[crr].gtri;
	push(crr);
	int mid=(l+r)/2;
	return max(get(crr*2,l,mid,lf,rt),get(crr*2+1,mid+1,r,lf,rt));
}
bool cmp(pl x, pl y){
	return x.w<y.w;
}
bool cmp2(rod x, rod y){
	return x.wei<y.wei;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("fishing.inp","r",stdin);
	freopen("fishing.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].w >> a[i].d >> a[i].v;
		nen.push_back(a[i].d);
	}
	sort(a+1,a+n+1,cmp);
//	nen.push_back(-1);
	sort(nen.begin(),nen.end());
	nen.erase(unique(nen.begin(),nen.end()),nen.end());
	int limit=nen.size();
	
	unordered_map<int, int> newv;
	for(int i=0;i<nen.size();i++) newv[nen[i]]=i+1;
	for(int i=1;i<=n;i++) a[i].d=newv[a[i].d];
	cin >> m;
	for(int i=1;i<=m;i++)  cin >> c[i].wei >> c[i].price;
	sort(c+1,c+1+m,cmp2);
	cin >> b;
	build(1,1,limit);
	int ind=1,sol=0;;
	for(int i=1;i<=m;i++){
		while(ind<=n&&a[ind].w<=c[i].wei){
			update(1,1,limit,a[ind].d,limit,a[ind].v);
			ind++;
		}
		sol=max(sol,get(1,1,limit,1,limit)-c[i].price);
	}
	cout << sol;
	return 0;
}

