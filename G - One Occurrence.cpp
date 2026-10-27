#include <bits/stdc++.h>
using namespace std;
int cnt[(const int) 1e6+5],sol[(const int)1e6+5];
//vector <int> chiacan[1005];
int sqr=0;
bool cmp(pair <int, pair <int, int > > a, pair <int, pair <int, int > > b){
	if(a.second.first/sqr!=b.second.first/sqr) return a.second.first/sqr<b.second.first/sqr;
	return a.second.second < b.second.second;
}

int main(){
	int n; cin >> n;
	sqr=sqrt(n);
	vector <int > a(n);
	vector <pair <int, pair <int, int > > > v;
	for(int i=0;i<n;i++) cin >> a[i];
	int t; cin >> t;
	int id=0;
	while(t--){
		int l,r; cin >> l >> r;
		v.push_back({id,{l-1,r-1}});
		id++;
	}
	sort(v.begin(),v.end(),cmp);
	set <int> hhh;
	for(int i=v[0].second.first;i<=v[0].second.second;i++){
		cnt[a[i]]++;
		hhh.insert(a[i]);
	}
	for(auto i : hhh) {
		if(cnt[i]==1) {
			sol[v[0].first]=i;
			break;
		}
	}
	int ans=sol[v[0].first];
	for(int i=1;i<v.size();i++){
		set <int> temp;
		if(v[i].second.first>v[i-1].second.first){
			for(int j=v[i-1].second.first;j<v[i].second.first;j++) {
				cnt[a[j]]--;
				temp.insert(a[i]);
			}
		}
		else if(v[i].second.first<v[i-1].second.first){
			for(int j=v[i].second.first;j<v[i-1].second.first;j++) {
				cnt[a[j]]++;
				temp.insert(a[i]);
			}
		}

		if(v[i].second.second>v[i-1].second.second){
			for(int j=v[i-1].second.second+1;j<=v[i].second.second;j++) {
				cnt[a[j]]++;
				temp.insert(a[i]);
			}
		}
		else if(v[i].second.second<v[i-1].second.second){
			for(int j=v[i].second.second+1;j<=v[i-1].second.second;j++) {
				cnt[a[j]]--;
				temp.insert(a[i]);
			}
		}
		for(auto i : temp) {
			if(cnt[i]==1) {
				ans=i;break;
			}
		}
		if(cnt[ans]==1)sol[v[i].first]=ans;
	}
	for(int i=0;i<v.size();i++) cout << sol[i] << "\n";
}
