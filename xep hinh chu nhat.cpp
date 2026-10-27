
#include<bits/stdc++.h>
#define int ull
using namespace std;
using ull = long long;
int s,c=0,b;
bool cmp(pair <int, int > a, pair <int, int > b)
{
	return a.first > b.first;
}
signed main()
{

//ios_base::sync_with_stdio(0);
//cin.tie(0);
	int t; cin>> t;
	while(t--){
		int n; cin >> n;int a[n];
		
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}
		sort(a,a+n);
		vector < pair <int, int > > v;
		v.push_back({a[0],1});
		for(int i=1;i<n;i++){
			if(a[i]==v[v.size()-1].first) v[v.size()-1].second++;
			else v.push_back({a[i],1});
		}
		int c1=0,c2=0;
		sort(v.begin(),v.end(),cmp);
		for(auto i : v){
			if(i.second>=4){
				c1=max(i.first,c1);
				c2=i.first;
				break;
			}
			if(i.second>=2&&i.first>0){
				if(c1==0) c1=i.first;
				else {
					c2=i.first; break;
				}
			}
		}
		if(c1==0||c2==0) {
			cout << "-1\n";
		}
		else cout << c1 * c2 << "\n";
	}
	return 0; 
}
