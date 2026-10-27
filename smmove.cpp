#include <bits/stdc++.h>
//#define int long long
using namespace std;
struct poin{
	long long x,y; 
	friend long long operator *(const poin &a,const poin &b){
		return a.x*b.y-a.y*b.x;
	}
	friend poin operator -(const poin &a,const poin &b){
		poin c;
		c={a.x-b.x,a.y-b.y};
		return c;
	}
};
poin a,b,m,n;
bool checkcat(){
	long long c1=(b-a)*(n-a), c2=(b-a)*(m-a);
	if(c1<=0&&c2<=0) return true;
	if(c1>=0&&c2>=0) return true;
	long long c3=(m-n)*(a-n), c4=(m-n)*(b-n);
	if(c3<=0&&c4<=0) return true;
	if(c3>=0&&c4>=0) return true;
	return false;
}
long double kc(const poin &A,const poin &B){
	return sqrtl((B.x-A.x)*(B.x-A.x)+(A.y-B.y)*(A.y-B.y));
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a.x >> a.y >> b.x >> b.y >> m.x >> m.y >> n.x >> n.y;
	cout << fixed << setprecision(4);
	if(checkcat()) {
		cout << kc(n,m);
		return 0;
	}
	cout << min(kc(n,a)+kc(a,m),kc(n,b)+kc(b,m));
	
	return 0;
}
