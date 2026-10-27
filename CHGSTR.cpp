#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
using namespace std;
long long n,m;
vector < char > a((const int) 1e5+5);
vector < vector < int > >  l(30);
void join ( vector <int >& a, vector <int >& b){
	if(a.size()<b.size()) a.swap(b);
	for(int i=0;i<b.size();++i) a.push_back(b[i]);
	b.clear();
}
int main(){
	freopen("CHGSTR.INP", "r", stdin);
    freopen("CHGSTR.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	string ss; cin >> ss;
	int z=0;
	for(int i=0;i<n;i++){
		l[ss[i]-'a'].push_back(z++);
	}
	
	for(int i=0;i<m;i++){
		string aa;  cin >> aa;char x=aa[0];char y=aa[1];
		if(x!=y){
			join(l[y-'a'],l[x-'a']);
		}
	}
	string s;
	s.resize(z);
	for(int i=0;i<26;i++){
		for(int j : l[i]) s[j]=i+'a';
	}
	cout << s;
}

