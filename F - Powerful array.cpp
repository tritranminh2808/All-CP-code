#include <bits/stdc++.h>
using namespace std;
int cnt[(const int) 1e6+5];
long long sol[(const int)1e6+5];
//vector <int> chiacan[1005];
int sqr=0;
bool cmp(pair <int, pair <int, int > > a, pair <int, pair <int, int > > b){
	if(a.second.first/sqr!=b.second.first/sqr) return a.second.first/sqr<b.second.first/sqr;
	return a.second.second < b.second.second;
}

int main(){
	int n,t; cin >> n>> t;
	sqr=sqrt(n);
	vector <int > a(n);
	vector <pair <int, pair <int, int > > > v;
	for(int i=0;i<n;i++) cin >> a[i];
	int id=0;
	while(t--){
		int l,r; cin >> l >> r;
		v.push_back({id,{l-1,r-1}});
		id++;
	}
	sort(v.begin(),v.end(),cmp);
	set<int> tempo;
	for(int i=v[0].second.first;i<=v[0].second.second;i++) {
		cnt[a[i]]++;
		tempo.insert(a[i]);
	}
	long long ans=0;
	for(auto i : tempo) ans+=cnt[i]*cnt[i]*i;
	
	sol[v[0].first]=ans;
	for(int i=1;i<v.size();i++){
		if(v[i].second.first>v[i-1].second.first){
			for(int j=v[i-1].second.first;j<v[i].second.first;j++) {
				ans=ans+a[j]-1ll*2*a[j]*cnt[a[j]];
				cnt[a[j]]--;
			}
		}
		else if(v[i].second.first<v[i-1].second.first){
			for(int j=v[i].second.first;j<v[i-1].second.first;j++) {
				ans+=a[j]+1ll*2*a[j]*cnt[a[j]];
				cnt[a[j]]++;
				
			}
		}

		if(v[i].second.second>v[i-1].second.second){
			for(int j=v[i-1].second.second+1;j<=v[i].second.second;j++) {
				ans+=a[j]+1ll*2*a[j]*cnt[a[j]];
				cnt[a[j]]++;
			}
		}
		else if(v[i].second.second<v[i-1].second.second){
			for(int j=v[i].second.second+1;j<=v[i-1].second.second;j++) {
				ans=ans+a[j]-1ll*2*a[j]*cnt[a[j]];
				cnt[a[j]]--;
			}
		}
		sol[v[i].first]=1ll*ans;
	}
	for(int i=0;i<v.size();i++) cout << sol[i] << "\n";
}
