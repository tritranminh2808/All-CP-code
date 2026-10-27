#include <bits/stdc++.h>
using namespace std;
int n;
vector < pair < int, pair <int , int > > > v;
bool cmp(pair < int, pair <int , int > > a, pair < int, pair <int , int > > b){
	if(a.second.first==b.second.first) return a.second.first <b.second.first;
	return a.second.second <b.second.second;
}
int main(){
	freopen("activity.inp","r",stdin);
	freopen("activity.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);
	 cin >> n ;
	 
	for(int i=0;i<n;i++){
		int ii,j; cin >> ii >> j;
		v.push_back({i,{ii,j}});
	}
	sort(v.begin(),v.end(),cmp);
//	for(auto i : v) cout << i.second.first << " " << i.second.second << "\n";
	int sol=0;
	vector <int > vv;
	int aa=v[0].second.first;
	for(int i=0;i<v.size();++i){
		if(v[i].second.first>=aa){
			sol++;
			aa=v[i].second.second;
			vv.push_back(v[i].first+1);
		}
	}
	cout << sol << "\n";
	//sort(vv.begin(),vv.end());
	for(auto i:vv) cout << i <<"\n";
	return 0;
}
