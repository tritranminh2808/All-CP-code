#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair <int,int> a, pair <int,int> b){
	return a.second >b.second;
}
int xu_li(int n){
	int s=1;
	for(int i=4;i<=n;i++) s*=i;
	return s;
}
int sol=0;
const int p=1e5+5;
int a[p];
signed main(){
	freopen("tgd010.inp","r",stdin);
	freopen("tgd010.out","w",stdout);
	int n; cin >> n;
	vector < pair <int, int > > v;
	for(int i=0;i<n;i++){
		cin>> a[i];
	}
	sort(a,a+n);
	v.push_back({a[0],1});
	for(int i=1;i<n;i++) {
		if(a[i]==v[v.size()-1].first) v[v.size()-1].second++;
		else v.push_back({a[i],1});
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v){
		if(i.second<3) break;
		if(i.first>0)sol+=xu_li(i.second);
	//	cout << i.second << " " << sol << "\n";
	}
	cout << sol;
	return 0;
}
