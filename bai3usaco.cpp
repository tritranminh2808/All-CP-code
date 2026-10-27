#include <bits/stdc++.h>
using namespace std;
int n,k; string s;
inline void maxxi(int& target, int value){
	if(target<value ) target = value;
}
int count(char c,char d){
	if(n<3) return 0;
	auto w=[&c,&d](int i){
		if(i<2) return 4;
		int res=0;
		if(s[i]!=d) ++res;
		if(s[i-1]!=d) ++res;
		if(s[i-2]!=c) ++res;
		return res;
	};
	vector <int> f(n,0),g(n,0);
	f[2]==w(2)==0 ? 1: 0;
	g[2]==w(2)<=1 ? 1 :0;
	for(int i=3;i<n;i++){
		f[i]=f[i-1];g[i]=g[i-1];
		maxxi(g[i],f[i]);
		int t=w(i);
		if(t==0){
			maxxi(f[i],f[i-3]+1);
			maxxi(g[i],g[i-3]+1);
		}
		else if(t==1){
			maxxi(g[i],f[i-3]+1);
		}
	}
	return g[n-1];
}
void xu_li(){
	count ('a','q');
	vector <pair <char, char > > moo;
	for(char c='a';c<='z';++c){
		for(char d='a';d <='z';d++){
			if(c!=d&&count(c,d)>=k) moo.push_back(make_pair(c,d));
		}
	}
	cout << moo.size() << "\n";
	for(pair <char,char>& p: moo) cout << p.first << p.second << p.second << "\n";
}
int main(){
	cin >> n >> k;
	cin >> s;
	xu_li();
	return 0;
}
