#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	long long n; cin >> n;

	vector < long long > v;
	while (n!=0)
	{
		v.push_back(n%2);
		n/=2;
	}
	for(long long i=v.size()-1;i>=0;i--) cout << v[i];
	
	return 0;
}
