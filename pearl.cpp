#include <bits/stdc++.h>
//#define int long long
using namespace std;
int cnt[(const int) 5e5+5],sol[500005];
int sqr=0,n;
int a[500005];
pair <int,int> v[500005];
void build(){
	sort(v+1,v+n+1);
	//for(int i=1;i<=n;i++) cout << v[i].first << " " << v[i].second << "\n";
	a[v[1].second]=1;
	int cntt=1;
	for(int i=2;i<=n;i++) {
		if(v[i].first!=v[i-1].first) a[v[i].second]=++cntt;
		else a[v[i].second]=cntt;
	}
}
void cook(int k){
	int c=0;
	for(int j=1;j<=k;j++) if(++cnt[a[j]]==1) c++;
	int res=c;
	for(int j=k+1;j<=n;j++) {
		if(++cnt[a[j]]==1) c++;
		if(--cnt[a[j-k]]==0) c--;
		if(j%k==0) res=min(res,c);
	}
	sol[k]=res;
	for(int i=0;i<=500000;i++) cnt[i]=0;
}
signed main(){
	cin >> n;
	sqr=sqrt(n);
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		v[i].first=a[i];
		v[i].second=i;
	}
	set<int> st;
	for(int i=1;i<=n;i++) st.insert(a[i]);
	build();
//	for(int i=1;i<=n;i++) cout << a[i];
	int sz=2;
	for(int i=2;i*i<n;i++){
		if(n%i==0){
			sz+=2;
			cook(i);
			cook(n/i);
		}
	}
	if(sqr*sqr==n) {
		sz++;
		cook(sqr);
	}
	cout << sz << "\n";
	cout << 1 << " " << 1 << "\n";
	for(int i=1;i<=n;i++){
		if(sol[i]>0) cout << i << " " << sol[i] << "\n";
	}
	cout << n << " " << st.size();
}

