#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("CATGIAY.INP","r+",stdin);
	freopen("CATGIAY.OUT","w+",stdout);
	int a,b; cin>>a >> b;
	int count=0;
	while (a!=b){
		int t=min(a,b);
		if(a>b) a-=t;
		else b-=t;
		count++;
	}
	cout<<count+1;
	return 0;
}
