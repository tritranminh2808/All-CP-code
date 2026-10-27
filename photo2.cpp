#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b; 
bool cmp(pair< pair <int, int > , int> x, pair< pair <int, int > , int> y){
	return x.first.first*a+x.first.second*b<y.first.first*a+y.first.second*b;
}
signed main(){
	int n,d; cin >> n >> d;
	cin >> a >> b;
	vector <pair< pair <int, int > , int >  > v;
	for(int i=0;i<n;i++){
		int l,r; cin >> l >> r;
		v.push_back({{l,r},i+1});
	}
	sort(v.begin(),v.end(),cmp);
	int dem=0;
	vector <int> res;
	for(int i=0;i<n;i++){
		if(d>=v[i].first.first*a+v[i].first.second*b){
			d-=v[i].first.first*a;
			d-=v[i].first.second*b;
			dem++;
			res.push_back(v[i].second);
		}
	}
	cout << dem << "\n";
	for(auto i : res) cout << i << " ";
	return 0;
}
