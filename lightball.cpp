#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> a(100005),b(100005),c(100005);

int cook(vector <int> a, vector <int> b, vector <int> c,int n, int m , int p){
	int sol=1000000000000000005;
	for(int i=1;i<=n;i++){
		int x1=lower_bound(b.begin()+1,b.begin()+m+1,a[i])-b.begin();
		int x2=lower_bound(c.begin()+1,c.begin()+p+1,a[i])-c.begin();
		int x=a[i],y1=b[x1],y2=b[x1-1],z1=c[x2],z2=c[x2-1];
		sol=min({sol,(x-y1)*(x-y1)+(y1-z1)*(y1-z1)+(z1-x)*(z1-x),(x-y1)*(x-y1)+(y1-z2)*(y1-z2)+(z2-x)*(z2-x),(x-y2)*(x-y2)+(y2-z1)*(y2-z1)+(z1-x)*(z1-x),(x-y2)*(x-y2)+(y2-z2)*(y2-z2)+(z2-x)*(z2-x)});
	}
	return sol;
}
signed main(){
	int n,m,p;
	cin >> n >> m >> p;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++) cin >> b[i];
	for(int i=1;i<=p;i++) cin >> c[i];
	b[0]=1000000005;
	c[0]=1000000005;
	sort(a.begin()+1,a.begin()+n+1);
	sort(b.begin()+1,b.begin()+m+1);
	sort(c.begin()+1,c.begin()+p+1);
	
	cout << min({cook(a,b,c,n,m,p),cook(b,a,c,m,n,p),cook(c,a,b,p,n,m)});
	return 0;
}
