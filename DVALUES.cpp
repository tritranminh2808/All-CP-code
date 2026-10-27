#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;cin >> n;
    set <int> a;int z;
    for(int i=0;i<n;i++) {
    	cin >> z;
    	a.insert(z);
	}
	vector <int > v;
    for(auto i:a) v.push_back(i);
    
    for(int i=v.size()-1;i>=0;i--) cout << v[i] << " ";
}
