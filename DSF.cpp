#include <bits/stdc++.h>
using namespace std;
long long n,m;
const long long p=1e6+4;
long long check[p];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	vector < pair < long long , long long > > v(m);
	for(long long i=0;i<n;i++) check[i+1]=i+1;
	for(long long i=0;i<m;i++){
		cin >> v[i].first >> v[i].second;
		if(check[v[i].first]!=check[v[i].second]){
			cout << "Y\n";
			for(long long j=0;j<n;j++){
				if(check[v[j].second]==check[v[i].second]) check[v[j].second]=check[v[i].first];
			}
		}
		else cout << "N\n";
	}
	return 0;
}
