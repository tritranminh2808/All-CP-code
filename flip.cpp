#include <bits/stdc++.h>
using namespace std;
//vector < vector < bool > > a(5,vector <bool> (5,0));
bool check(int a){
	if(a==0||a==(1<<16)-1) return true;
	return false;
}
int lat(int x, int l, int r){
	int pos=4*l+r;
	x=x^(1<<pos);
	if(l>0) x^=(1<<((l-1)*4+r));
	if(r>0) x^=(1<<(l*4+r-1));
	if(l<3) x^=(1<<((l+1)*4+r));
	if(r<3) x^=(1<<(l*4+r+1));
	return x;
}
void cok(){
	int a=0;
	for(int i=0;i<4;i++){
		string s; cin >> s;
		for(int j=0;j<4;j++) {
			if(s[j]=='T') a|=(1<<(i*4+j));
		}
	}
	vector <int> cnt(1<<16,-1);
	queue<int> q;
	cnt[a]=0;
	q.push(a);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(check(cur)){
			cout << cnt[cur] <<"\n";
			return;
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				int next=lat(cur,i,j);
				if(cnt[next]==-1){
					cnt[next]=cnt[cur]+1;
					q.push(next);
				}
			}
		}
	}
	cout << -1 << "\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
	while(q--){
		cok();
	}
	return 0;
}
