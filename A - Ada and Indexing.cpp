#include <bits/stdc++.h>
using namespace std;
int st[1000005][26];
int cnt[1000005];
int node=0;
void update(string s){
	int id=0;
	for(int i=0;i<s.length();i++){
		int nid=st[id][s[i]-'a'];
		if(nid==-1){
			st[id][s[i]-'a']=++node;
			nid=node;
		}
		cnt[nid]++;
		id=nid;
	}
}
int find(string s){
	int id=0;
	for(int i=0;i<s.length();i++){
		int nid=st[id][s[i]-'a'];
		if(nid==-1) return 0;
		id=nid;
	}
	return cnt[id];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i=0;i<1000005;i++){
		for(int j=0;j<40;j++) st[i][j]=-1;
	}
	while(n--){
		string s; cin >> s;
		update(s);
	}
	while(q--){
		string qr; cin >> qr;
		cout << find(qr) << "\n";
	}
	return 0;
}

