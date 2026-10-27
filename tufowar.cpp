#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int, int > a, pair <int, int > b){
	return a.first < b.first;
}
int main(){

	freopen("tugofwar.inp","r",stdin);
	freopen("tugofwar.out","w",stdout);
		ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector < pair < int, int > > v;
	for(int i=0;i<n;i++) {
		int k; cin >> k;
		v.push_back({k,i+1});
	}
	sort(v.begin(),v.end(),cmp);
	vector <int> v1,v2;
	int t1,t2;
	v1.push_back(v[0].second);
	t1=v[0].first;
	t2=0;
	for(int i=1;i<n;i++){
		if(abs(t1+v[i].second-t2)<abs(t2+v[i].second-t1)){
			v1.push_back(v[i].second);
			t1+=v[i].second;
		}
		else {
			v2.push_back(v[i].second);
			t2+=v[i].second;
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	cout << v1.size() << " " << v2.size() << "\n";
	for(auto i: v1) cout << i << " ";
	cout << "\n";
	for(auto i: v2) cout << i << " ";
}
