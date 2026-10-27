#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
long long A,B,res;
bool cmp(pair <int, int> a, pair <int, int > b){
	return a.second > b.second;
}
unordered_map<int,bool> mp;
unordered_map<int,int> mp2;
signed main(){
//	freopen("tesst.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n >> A >> B;
	
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		mp2[a[i]]++;
	}
	sort(a+1,a+n+1);
	vector < pair <int, int > > v;
	v.push_back({a[1],1});
	for(int i=2;i<=n;i++){
		if(a[i]==v[v.size()-1].first) v[v.size()-1].second++;
		else v.push_back({a[i],1});
	}
	sort(v.begin(),v.end(),cmp);
//	for(auto i : v) cout << i.first << " " << i.second << "\n";
	int q=n;
	vector <int> carlsen, liem;
	bool luot=1;
	for(int i=v.size()-1;i>=0;i--){
		if(luot==1) {
			carlsen.push_back(v[i].first);
			v[i].second--;
			if(v[i].second==0) v.pop_back();
			luot=0;
		}else{
			liem.push_back(v[i].first);
			v[i].second--;
			if(v[i].second==0) v.pop_back();
			luot=1;
		}
	}
//	for(auto i : carlsen) cout << i << " ";
//	cout << "\n";
//	for(auto i: liem ) cout << i <<" ";
//	cout << "\n";
	 
	for(int i=0;i<carlsen.size();i++){
		if(mp[carlsen[i]]!=1) {
			res+=A;
			mp[carlsen[i]]=1;
		}
		if(mp2[carlsen[i]]==1) res+=B;
		if(i>=liem.size()) continue;
		mp[liem[i]]=1;
	}
	cout << res;
	return 0;
}
