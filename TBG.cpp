#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("TBG.INP","r+",stdin);
	freopen("TBG.OUT","w+",stdout);
	int x,y,z;cin >> x >> y >> z;int n;
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t=y*z;int i=1;int k=i*y+t;while (k<x*z){
		i++;k=i*y+t;
	}cout << i;
	return 0;
}
