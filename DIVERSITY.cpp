#include <bits/stdc++.h>
using namespace std;
bool chck(int n){
	int t=0;for(int i=1;i<n;i++){
		if(n%i==0) t+=i;
		if(t>n) return true;
	}return false;
}
int main()
{
	freopen("DIVERSITY.INP","r+",stdin);
	freopen("DIVERSITY.OUT","w+",stdout);
	int n,m; cin >> n >> m;for(int i=n;i<m;i++){
		if(chck(i)) cout << i << " ";
	}
	return 0;
}
