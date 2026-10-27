#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
using namespace std;
const int p=1e6+5;
long long b[p],a[p];
long long n,m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;  
    vector <int> v;
    for(int i=0;i<n;i++)
	{
		cin >> a[i];v.push_back(a[i]);
	} 
	for(int i=0;i<m;i++) {
		cin >> b[i];
		auto it=find(v.begin(),v.end(),b[i]);
		if(it!=v.end())v.erase(it);
		
	}
	for(auto i : v) cout << i << " ";
	
}

