#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")
using namespace std;
const int p=1e7+1;
bool check[p];
bool snt(int n){
	if(n<1) return false;
	for(int i=2;i*i<=n;++i){
		if(n%i==0) return false;
	}
	return true;
}
int so_dao(int n){
	vector <int> v;
	while(n!=0){
		v.push_back(n%10);n/=10;
	}
	int t=0;
	for(int i=0;i<v.size();i++){
		t+=v[i];t*=10;
	}t/=10;
	return t;
}
int main(){
	int n;cin >> n;
	vector <int> v;
	for(int i=2;i<=n;i++){
		if(i<10&&snt(i)) cout << i << " ";
		else if(snt(i)&&snt(so_dao(i))&&check[i]==0) {
			//cout << i << " ";
			v.push_back(i);
			if(so_dao(i)!=i&&so_dao(i)<=n)v.push_back(so_dao(i));
			check[so_dao(i)]=1;
		}
		//cout << so_dao(i) << endl;;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++) cout << v[i]  << " ";
	return 0;
}
