#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
int n; 
struct poin{
	int x,y; 
	friend long long operator *(const poin &A, const poin &B){
		return A.x*B.y-A.y*B.x;
	} 
	friend poin operator -(poin A, poin B){
		poin c={A.x-B.x,A.y-B.y};
		return c;
	}
};
poin s[1000005];
poin bao[1000005];
bool check(const poin &d, const poin &e, const poin &f){
	if((e-d)*(f-e)>0) return true;
	return false;
}
int m=0;
bool sech(int i, int j, int s){
	return (bao[i].y-s)*bao[j].x>(bao[j].y-s)*bao[i].x;
}
void find(int p){
	int l=0,r=m-1;
	while(l<r){
		int mid=(l+r)/2;
		if(sech(mid+1,mid,p))l=mid+1;
		else r=mid;
	}
	int ts=bao[l].x,ms=bao[l].y-p;
	int g=__gcd(ts,ms);
	cout << ts/g << " " << ms/g << "\n";;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) {
		s[i].x=i;
		s[i].y=a[i];
	}
	
	for(int i=1;i<=n;++i){
		while(m>=2&&check(bao[m-2],bao[m-1],s[i])) m--;
		bao[m++]={s[i].x,s[i].y};
	}
	int q; cin >> q;
	while(q--){
		int x;cin >> x;
		find(x);
	}
//	for(int i=0;i<m;i++) cout << bao[i].y << "\n";
	return 0;
}
