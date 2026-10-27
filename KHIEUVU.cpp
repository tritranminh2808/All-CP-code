#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("KHIEUVU.inp","r",stdin);
	freopen("KHIEUVU.out","w", stdout);
	int n,k;
	cin>>n>>k;
	int a;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int dem=0;
	for(int i=0;i<n;i++){
		
		if(binary_search(v.begin(),v.end(),v[i]-k)) dem++;
	}
	cout<<dem;
}
