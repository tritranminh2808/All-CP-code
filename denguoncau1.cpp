#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int a,b,m; 
	cin>> a >> b >> m;
	b-=b%m;
	a+=m-a%m;
	int x=(b-a)/m;
	cout << (x+1)*x/2;
}
