#include <bits/stdc++.h>
//#define int long long
using namespace std;
int a[100005];
int block[1005];
int main(){
//	freopen("sacso.inp","r",stdin);
//	freopen("sacso.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin >> n >> q;
	for(int i=0;i<=1000;i++) block[i]=1;
	string s; cin >> s;
	for(int i=0;i<s.length();++i) {
		if(s[i]=='G') a[i]=0;
		if(s[i]=='R') a[i]=1;
		if(s[i]=='B') a[i]=2;
		if(s[i]=='Y') a[i]=3;
	}
	int can=sqrt(n);
	for(int i=1;i<n;i++){
		if(i%can==0) i++;
		if(i>=n) break;
		if(a[i]!=a[i-1]) block[i/can]++;
	}
//	for(int i=0;i<=can;i++) cout << block [i] << " ";
	while(q--){
		string p; cin >> p;
		int l,r; cin >> l >> r;
		l--;
		r--;
		if(p[0]=='g'){
			int sol=2;
			for(int i=l+1;i<min((l/can+1)*can,n);i++) if(a[i]!=a[i-1]) sol++;
			for(int i=(r/can)*can+1;i<=r;i++) if(a[i]!=a[i-1]) sol++;
			if(a[(r/can)*can]==a[(r/can)*can-1]) sol--;
			int stt=l/can+1,end=r/can-1;
			for(int i=stt;i<=end;i++){
				sol+=block[i];
				if(a[i*can]==a[i*can-1]) sol--;
			}
			cout << sol << "\n";
		}
		else {
			char c; cin >> c;
			int udt;
			if(c=='G') udt=0;
			if(c=='R') udt=1;
			if(c=='B') udt=2;
			if(c=='Y') udt=3;
			for(int i=l;i<=r;i++) a[i]=udt;
			block[l/can]=1;
			for(int i=(l/can)*can+1;i<min((l/can+1)*can,n);i++) if(a[i]!=a[i-1]) block[l/can]++;
			block[r/can]=1;
			for(int i=(r/can)*can+1;i<min((r/can+1)*can,n);i++) if(a[i]!=a[i-1]) block[r/can]++;
			int stt=l/can+1,end=r/can-1;
			for(int i=stt;i<=end;i++) block[i]=1;
//			for(int i=0;i<sqrt(n);i++) cout << block[i] << " ";
		}
	}
}
