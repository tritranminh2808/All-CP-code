#include <bits/stdc++.h>
using namespace std;
bool cmp( pair <int,int > a , pair <int,int> b){
	return a.first*b.second<a.second*b.first;
}
int main(){
	freopen("Phanso.inp","r",stdin);
	freopen("Phanso.out","w",stdout);
	int n;cin >> n;
	vector <pair < int ,  int > > v(n);
	for(int i=0;i<n;i++) cin >> v[i].first;
	for(int i=0;i<n;i++) cin >> v[i].second;
	for(int i=0;i<n;i++){
		int k=__gcd(v[i].first,v[i].second);
		v[i].first/=k;
		v[i].second/=k;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;++i){
		cout << v[i].first << " ";
	}
	cout << "\n";
	for(int i=0;i<n;++i){
		cout << v[i].second << " ";
	}
	return 0;
}
