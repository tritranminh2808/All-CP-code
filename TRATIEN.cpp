#include <bits/stdc++.h>
using namespace std;


int n;
int main()
{

	int t; cin >> t;
	while(t--){
		cin >> n;
		long long dem=0;
		for (int t10=0; t10<=n;t10++)
		{
			for (int t20=0; t20<=n/2-t10/2;t20++)
			{
				if (t10*1+t20*2+((n-(t10*1+t20*2))/5)*5==n)
				{
					dem++;
				}
			}
		}
	cout << dem << endl;
	}
	return 0;
}
