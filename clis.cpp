#include <bits/stdc++.h>
using namespace std;
const long long p=1e7+1;
vector <int> a;
long long f[p],e[p];
int main(){
	string s; cin >> s;
	for(auto i : s) a.push_back(int(i));
	long long sol=0;
	for(int i=0;i<a.size();i++){
		f[i]=upper_bound(e+1,e+sol+1,a[i])-e;
		if(f[i]>sol) sol++;
		e[f[i]]=a[i];
	}
	cout << sol;
}
