#include <bits/stdc++.h>
using namespace std;

bool cmp (string a,string b){
	return a+b>b+a;
}
int main()
{
	freopen("maxnum.inp","r",stdin);
	freopen("maxnum.out","w",stdout);
	long long n;cin >> n;
	vector <string> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	
	sort (v.begin(),v.end(),cmp);
	for (long long i=0;i<v.size();i++) cout << v[i] ;
	return 0;
}
