#include <bits/stdc++.h>
//#define int long long
using ll=long long;
using namespace std;

int n; 
struct poin{
	ll x,y; 
	friend long long operator *(const poin &A, const poin &B){
		return A.x*B.y-A.y*B.x;
	} 
	friend poin operator -(poin A, poin B){
		poin c={A.x-B.x,A.y-B.y};
		return c;
	}
};
bool ccw(poin d, poin e,poin f){
	return (e-d)*(f-e)<=0;
}
bool cmp(poin a,poin b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
ll len(poin a){
	return a.x*a.x+a.y*a.y;
}
poin goc;
bool cmp2(poin a, poin b){
	ll l=(a-goc)*(b-goc);
	return l>0||l==0&&len(a-goc)<len(b-goc);
}
//int n;
poin a[1000005],bao[1000005], b[100005];
//bool /
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin>> a[i].x >> a[i].y; 
	sort(a+1,a+n+1,cmp);
	goc=a[1];
//	cout << goc.x << " " << goc.y ;
	sort(a+2,a+n+1,cmp2);
//	for(int i=1;i<=n;i++) cout << a[i].x << " " << a[i].y << "\n";
	int m=0;
	for(int i=1;i<=n;i++){
		while(m>=2&&ccw(bao[m-2],bao[m-1],a[i])) m--;
		bao[m++]=a[i];
	}
	int m; cin >> m;
	for(int )
	return 0;
}
