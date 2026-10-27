#include <bits/stdc++.h>
#define int long long
using namespace std;
//int a[1000005];

int n,K,m;
int cook1(vector <int> a, vector <int> b){
	int sol=0;
	sort(a.begin(),a.end());
	int cnt=0;
	for(int i=0;i<n;i++) {
		if(cnt+a[i]>K) break;
		cnt+=a[i];
		sol++;
	}
	for(int i=sol;i<n;i++) b.push_back(a[i]);
	sort(b.begin(),b.end());
	cnt=0;
	for(int i=0;i<b.size();i++) {
		if(cnt+b[i]>K) break;
		cnt+=b[i];
		sol++;
	}
	return sol;
}
int cook2(vector<int> a, vector<int> b){
	vector <pair<int, int > > v;
	for(int i=0;i<n;i++) v.push_back({a[i],i});
	for(int i=0;i<m;i++) v.push_back({b[i],-1});
	int sol=0;
	sort(v.begin(),v.end());
	int cnt=0;
	unordered_map<int, bool> mp;
	for(int i=0;i<v.size();i++){
		if(cnt+v[i].first>K) break;
		cnt+=v[i].first;
		sol++;
		if(v[i].second!=-1) mp[v[i].second]=1;
	}
	vector <int> c;
	for(int i=0;i<n;i++) if(mp[i]!=1) c.push_back(a[i]);
	sort(c.begin(),c.end());
	cnt=0;
	for(int i=0;i<c.size();i++) {
		if(cnt+c[i]>K) break;
		cnt+=c[i];
		sol++;
	}
	return sol;
}
signed main(){
	 cin >> K;
	cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;i++) cin>> a[i];
	
	cin >> m;
	vector <int> b(m);
	for(int i=0;i<m;i++) cin >> b[i];
	cout << max(cook2(a,b),cook1(a,b));
	
	return 0;
}

