#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin >> n;
	vector <int > a,v;
	for(int i=0;i<n;i++){
		int k; cin >> k;
		a.push_back(k);
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	vector < pair <int , int > > s;
	for(int i=0;i<n;i++){
		if(a[i]!=v[i]){
			for(int j=i+1;j<n;j++){
				if(a[j]==v[i]){
					s.push_back({i,j});
					swap(a[i],a[j]);
					break;
				}
			}
		}
	}
	cout << s.size() << "\n";
	for(auto i : s) cout << i.first << " " << i.second <<"\n";
}

