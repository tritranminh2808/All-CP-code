#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005],b[1005];
vector <int> v,A,B;
int n,m,k;
int sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int j=0;j<m;j++) cin >> b[j];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) A.push_back(a[i]+a[j]);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++) B.push_back(b[i]+b[j]);
	}
	for(int i=0;i<A.size();i++){
		for(int j=0;j<B.size();j++) v.push_back(A[i]+B[j]);
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=max((int)0,(int)v.size()-k);--i) sol+=v[i];
	cout << sol;
}
