#include <bits/stdc++.h>
using namespace std;
const long long pp=1e6+5;
bool check [pp];
long long sol=1;
int main() {
	long long a;cin >> a;
	long long p=2;
	vector <int> v;
	while(p<=a){
		v.push_back(p);
		a-=p;p++;
	}
	reverse(v.begin(),v.end());
	int k=0;
	while(a>0){
		v[k]+=1;
		a-=1;k+=1;
		if(k>=v.size()) k=0;
	}
	for(int i=v.size()-1;i>=0;--i) cout << v[i] << "\n";
}
