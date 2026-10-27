#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=0;
struct ST{
	int a,b,c, ind;
};
ST s[1000005],t[1000005];
vector <int> A,B,C;
struct cmp{
	bool operator()(pair <int, int > a, pair <int, int > b){
		return a.first < b.first;
	}
};
signed main(){
	int m,n,p; cin >> m >> n >> p;
	int k=m+n+p;
	for(int i=1;i<=k;i++) {
		cin >> s[i].a >> s[i].b >> s[i].c;
		t[i].a=s[i].a;
		t[i].b=s[i].b;
		t[i].c=s[i].c;
		t[i].a-=t[i].c;
		t[i].b-=t[i].c;
		t[i].ind=i;
	}
	sort(t+1,t+k+1,[](ST x, ST y){
		return x.a-x.b<y.a-y.b;	
	});
	sort(t+1+m,t+k+1,[](ST x, ST y){
		return x.b<y.b;	
	});
	priority_queue< pair <int, int > , vector <pair <int, int > > , cmp> pq;
	for(int i=1;i<=m;i++) A.push_back(t[i].ind);
	for(int i=m+1;i<=m+n;i++) B.push_back(t[i].ind);
	for(int i=m+n+1;i<=k;i++) C.push_back(t[i].ind);
	for(auto i:A) sol+=s[i].a;
	for(auto i:B) sol+=s[i].b;
	for(auto i:C) sol+=s[i].c;
	cout << sol;
	return 0; 
}

