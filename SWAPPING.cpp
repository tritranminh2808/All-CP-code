#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
int a[p];
int n; int min1=INT_MAX,min2=INT_MAX,m1,m2;
int main(){
	//freopen("SWAPPING.INP", "r", stdin);
   // freopen("SWAPPING.OUT", "w", stdout);
	cin >> n;vector <int> b;
	for(int i=1;i<=n;++i) {
		cin>> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(),b.end());
	int k1=b[b.size()-1],k2=b[b.size()-2];
	vector <int> x,y;
	for(int i=1;i<=n;i++) {
		if(a[i]==k1) x.push_back(i);
		if(a[i]==k2) y.push_back(i);
	}
	cout << min(x[0]-1+n-y[y.size()-1],y[0]-1+n-x[x.size()-1]);
	return 0;
}

