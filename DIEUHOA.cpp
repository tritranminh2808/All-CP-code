#include <bits/stdc++.h>
using namespace std;
bool cmp(pair < int , int > a ,  pair < int , int > b){
	return a.first < b.first;
}
long long res;
int main()
{ 
	freopen ("DIEUHOA.inp","r",stdin);
	freopen ("DIEUHOA.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)    cin>>a[i];
	int m; cin >> m;
	vector < pair < int , int > > v(m);
	for(int i=0;i<m;i++) cin>>v[i].first >> v[i].second;
	sort(v.begin(),v.end(),cmp);
	//for(int i=0;i<m;i++) cout<< v[i].first << " "<< v[i].second<<endl;
	sort(a,a+n);
	int i=n-1,j=m-1;
	//cout << v[j].first << " " <<v[j].second <<"\n";
	while (i>=0){
		int cost=9999999;
		int k=j;
		while (v[k].first>=a[i]) {	
			cost=min(v[k].second,cost);
			k--;
		}
		res+=cost;
		//cout << res << "\n";
		i--;
	}
	cout << res;
	return 0;
}
