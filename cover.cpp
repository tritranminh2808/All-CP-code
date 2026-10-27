#include <bits/stdc++.h>
using namespace std;
int n, a , b;
vector < pair < int, int > > v;
bool cmp(pair <int,int> a, pair<int,int> b){
	if(a.first==b.first) return a.second> b.second;
	return a.first <b.first;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	 cin >> n >> a >> b;
	 
	for(int i=0;i<n;i++){
		int ii,j; cin >> ii >> j;
		v.push_back({ii,j});
	}
	sort(v.begin(),v.end(),cmp);
	int sol=0;
	do{
		int m=a-1,ind;
		for(int i=0;i<v.size();++i){
			if(v[i].first<=a&&v[i].second>=a){
				if(v[i].second>m){
					m=v[i].second;
					ind=i;
				}
			}
		}
		if(m<a){
			cout << -1;return 0;
		}
		v.erase(v.begin()+ind);
		sol++;
		a=m;
	}while(a<b);
	cout << sol;
	return 0;
}

