#include <bits/stdc++.h>
using namespace std;
int a[100005];
pair<int, int > q[100005];
int n,m,k,maxx=-1;
string sol;

void check(string s){
	int x=0;
	for(int i=1;i<=m;i++){
		int start=q[i].first , end=q[i].second;
		int cnt=0,ind=0;
		for(int j=1;j<=n;j++){
			if(a[i]>end) break;
			if(a[i]>=start) {
				if(s[j-1]=='K') cnt++;
				else cnt--;
			}
		}
		if(abs(cnt)<=k) x++;
	}
	if(x>=maxx){
		maxx=x;
		sol=s;
	}
	if(maxx==m){
		cout << maxx << "\n" << sol;
		exit(0);
	}
}
void cok(string sec){
	if(sec.length()==n){
		check(sec);
		return;
	}
	cok(sec+'K');
	cok(sec+'N');
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	for(int i=0;i<4000000;i++) st[i]=1;
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i)cin >> a[i];
	for(int i=1;i<=m;i++) cin >> q[i].first>> q[i].second;
	cout << m << "\n";
	for(int i=0;i<n;i++) {
		if(i%2==0) cout << "K";
		else cout << "N";
	}
	return 0;
}
