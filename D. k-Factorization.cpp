#include <bits/stdc++.h>
#define int long long
using namespace std;
signed  main(){
	int n,k; cin >> n >> k;
	vector <int > v;
	int sss=sqrt(n);
	for(int i=2;i<=sss;i++){
		while(n%i==0){
			v.push_back(i);
			n/=i;
		}
	} 
	if(n!=1) v.push_back(n);
	 if(v.size()<k) {
	 	cout << -1;return 0;
	 }
	 vector <int > sol; int d=1;
	for(int i=0;i<=v.size()-k;i++){
		d*=v[i];
	}
	cout << d << " ";
	for(int i=v.size()-k+1;i<v.size();i++) cout << v[i] << " ";
	return 0;
}
