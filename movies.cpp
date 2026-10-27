#include <bits/stdc++.h>
using namespace std;
int sol;
int n;
bool cmp(pair <int,int> a, pair <int, int > b){
	if(a.first==b.first) return a.second < b.second;
	return a.first < b.first;
}
void xu_li(vector < pair <int, int > > v){
	sort(v.begin(),v.end(),cmp);
	int l=v[0].first, r=v[0].second;
	sol++;
	for(int i=1;i<v.size();++i){
		if(v[i].first>=r){
			l=v[i].first;
			r=v[i].second;
			sol++;
		}
		else continue;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	vector < pair <int, int> > v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;
	}
	xu_li(v);
	cout << sol;
}
