#include <bits/stdc++.h>
using namespace std;
int n,q,sqr;
int cnt[224][100005],a[50004];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	sqr=sqrt(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cnt[i/sqr][a[i]]++;
	while(q--){
		int l,r,x; cin >> l >> r >> x;
		l--;
		r--;
		int x1=l/sqr;
		int sol=0;
		for(int i=l;i<(x1+1)*sqr;i++) if(a[i]==x) sol++;
//		cout << sol << " ";
		int x2=r/sqr;
		for(int i=r;i>=x2*sqr;i--) if(a[i]==x) sol++;
		for(int i=x1+1;i<x2;i++) sol+=cnt[i][x];
		cout << sol << "\n";
	}
}
