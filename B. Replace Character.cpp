#include <bits/stdc++.h>
using namespace std;
bool cmp( pair <char,int> a, pair <char, int > b){
	return a.second > b.second;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;string ss; cin >> ss;
		vector <char> s; for(auto i: ss) s.push_back(i);
		sort(s.begin(),s.end());
		vector <pair <char , int > > v;
		v.push_back({s[0],1});
		for(int i=1;i<n;i++){
			if(s[i]==v[v.size()-1].first) v[v.size()-1].second++;
			else v.push_back({s[i],1});
		}
		sort(v.begin(),v.end(),cmp);
	//	for(auto i : v) cout << i.first << " " << i.second << endl;
		char a1=v[0].first,a2=v[v.size()-1].first;
		bool check=0;
		for(auto i:ss){
			if(i==a2&&check==0){
				cout << a1;
				check=1;
			}
			else cout << i;
		}
		cout << "\n";
	}
	return 0;
}
