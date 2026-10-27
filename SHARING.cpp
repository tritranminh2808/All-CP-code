#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")
long long l=0,r=0,n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
     cin >> n;

    vector <int> v;
    for(int i=0;i<n;i++) {
    	int t; cin >> t;
    	v.push_back(t);
	}
    
    while(!v.empty()){
    	if(l<r){
    		l+=v[0];
    		v.erase(v.begin()+0);
		}
		else {
			r+=v[v.size()-1];
			v.erase(v.begin()+v.size()-1);
		}
	}
	cout << l << "\n" << r;
}
