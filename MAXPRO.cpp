#include <bits/stdc++.h>
using namespace std;
int main()
{

	long long a,b,c,k;cin >> a >> b >> c >> k;
	cout << max({a*b,b*c,c*a})%k;
	return 0;
}
