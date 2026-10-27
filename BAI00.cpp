#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long S,x,y,c;
	cin >> S >> x >> y >> c;
	if((long double)c/x<(long double)(S-c)/y){
		cout << "A";return 0;
	}
	else if((long double)c/x==(long double)(S-c)/y){
		cout << "AB";return 0;
	}
	cout << "B";
	return 0;
}
