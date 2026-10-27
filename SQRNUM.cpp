#include <bits/stdc++.h>
using namespace std;
const long long p=1e5+5;
long long sol=1;
long long power (long long a, long long b){
	long long t=1;while(b--) t*=a;
	return t;
}
int main(){
	long long n;cin >> n;
	vector < pair < long long , long long > > v;
	for(long long i=2;i<=sqrt(n);++i){
		if(n%i==0){
			v.push_back({i,1});
			n/=i;
		}
		while(n%i==0){
			v[v.size()-1].second++;
			n/=i;
		}
	}
	if(v.size()==0)  v.push_back({n,1});
	else if(n!=1&&n!=v[v.size()-1].first) v.push_back({n,1});
	else if (n!=1&&n==v[v.size()-1].first) v[v.size()-1].second++;
	for(long long i=0;i<v.size();i++){
		sol*=power(v[i].first,v[i].second);
		if(v[i].second%2!=0) sol*=v[i].first;
	}
	cout << sol;
	 
 	return 0;
}
