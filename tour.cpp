#include <bits/stdc++.h>
using namespace std;
long long res;
const int p=1e7+7;
bool check[p];
int main ()
{
	freopen("tour.INP","r",stdin);
	freopen("tour.OUT","w",stdout);
	int n,m; cin >> n >> m;
	int a[n], b[m],c[m];
	for(int i=0;i<n;i++)  cin >> a[i];
	for(int i=0;i<m;i++) {
		cin >> b[i];
		c[i]=b[i];
	}
	sort(a,a+n);
	sort(b,b+m);
	int j=0;
	vector <int> v;
	for(int i=n-1;i>=0;--i){
		v.push_back(b[i]);
		res+=b[i]*a[j];
		j++;
	}
	cout << res << "\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<v.size();j++){
			if(c[i]==v[j]&&check[j]==0){
				cout << i+1 << "\n";
				check[j]=1;
			}
		}
	}
	return 0;
}
