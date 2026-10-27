#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair <long long,long long> a,pair<long long,long long> b){
	return a.first <b.first;
}
bool cmp2(pair <long long,long long> a,pair<long long,long long> b){
	return a.second >b.second;
}
int main(){
	long long n; cin >> n;
	long long a[n];long long b[n];
	for(long long i=0;i<n;i++) cin >> a[i];
	vector <long long> v1;vector <long long> v2;
	for(long long i=0;i<n;i++) {
		cin >> b[i];
		if(b[i]>a[i]) v1.push_back(i);
		else v2.push_back(i);
	}
	int p=v1.size(),q=v2.size();
	vector < pair < long long , long long > > A (p);
	vector < pair < long long , long long > > B (q);
	for(long long i =0;i<p;i++){
		A[i].first=a[v1[i]];
		A[i].second=b[v1[i]];
	}
	for(long long i =0;i<q;i++){
		B[i].first=a[v2[i]];
		B[i].second=b[v2[i]];
	}
	sort (A.begin(),A.end(), cmp1);
	sort(B.begin(),B.end(),cmp2);
	long long sol=0,zz=0;
	/*for(long long i=0;i<p;i++){
		sol-=A[i].second;
		sol+=A[i].first;
	}
	for(long long i=0;i<q;i++){
		sol-=B[i].second;
		sol+=B[i].first;
	
	}
	sol+=B[v2.size()-1].second;*/
	for(long long i=0;i<p;i++){
		
		
		if(zz<A[i].first){
			sol+=(A[i].first-zz);
			zz=A[i].first;
		}
		zz-=A[i].first;
		zz+=A[i].second;
	}
	for(long long i=0;i<q;i++){
		
	
		if(zz<B[i].first){
			sol+=(B[i].first-zz);
			zz=B[i].first;
		}
		zz-=B[i].first;
		zz+=B[i].second;
	}
	 
	cout << sol;
	return 0;
}
