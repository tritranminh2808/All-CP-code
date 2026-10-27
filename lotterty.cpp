#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target ("abm,avx2,bmi,bmi2")
using namespace std;

long long sol=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n,k;cin >> n >> k;
	int a[n+1];for(int i=1;i<=n;i++) cin >> a[i];
	long long x,y; cin >> x >> y;
	sort(a+1,a+n+1);
	vector <pair < int , int > > v;
	
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) v.push_back({a[i],1});
		else v[v.size()-1].second++;
	}
	for(int  i=x;i<=y;i++){
		int dem=0;
		for(int j=0;j<v.size();j++){
			if(i%v[j].first==0) dem+=v[j].second;
			if(dem>k) break;
			
		}
		if(dem==k) sol++;
	}
	
	cout << sol;
}
