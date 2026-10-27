#include <bits/stdc++.h>
using namespace std;
const long long p=1e7+1;
long long a[p];
long long f[p],e[p];
bool cmp(pair <int,int> a, pair<int,int > b){
	return a.first < b.first;
}
int main(){
	long long n,k; cin >> n>>k;
	vector <pair <int, int > > v;
	for(long long i=0;i<n;i++) {
		long long x,y; cin >> x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end(),cmp);
	int j=0;
	for(auto i:v) {
		a[j]=i.first+k*i.second;j++;
	}
	reverse(a,a+n);
	long long sol=0;
	for(int i=0;i<n;i++){
		f[i]=upper_bound(e,e+sol,a[i])-e;
		if(f[i]>=sol) sol++;
		e[f[i]]=a[i];
	}
	cout << sol;
}
