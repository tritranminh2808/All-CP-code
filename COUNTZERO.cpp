#include <bits/stdc++.h>
using namespace std;
unsigned long long a,cstc=0;
int main()
{
	cin >> a;
	while (a>=5){
		a/=5;	cstc+=a;
	}
	cout << cstc;
	return 0;
}
