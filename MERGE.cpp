#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;cin >> n>>m;
    vector <int> a;int z;
    for(int i=0;i<n+m;i++) {
    	cin >> z;
    	a.push_back(z);
	}
	
    sort(a.begin(),a.end());
    for(auto i:a) cout << i << " ";
}
