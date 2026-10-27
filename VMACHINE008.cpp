#include <bits/stdc++.h>
using namespace std;

int main()
{ 
	freopen ("VMACHINE008.inp","r",stdin);
	freopen ("VMACHINE008.out","w",stdout);
	long long n; cin >> n;
	
	for(long long i=0;i<n;i++){
		long long k;
		cin >>k;
		long long z=0;
		vector <long long> v;
		while(z*2<=k){
			if(z==0) z++;
			else z*=2;
			v.push_back(z);
		}
		cout << v.size() << "\n";
		for(long long i=0;i<v.size();i++) cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}
