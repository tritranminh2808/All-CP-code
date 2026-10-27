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
	if((e-d)*(f-e)<=0) return true;
	return false;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++) {
		s[i].x=i;
		s[i].y=a[i];
	}
	int m=0;
	bao[m++]={0,0};
	for(int i=1;i<=n;++i){
		while(m>=2&&check(bao[m-2],bao[m-1],s[i])) m--;
		bao[m++]={s[i].x,s[i].y};
	}
	long double TT=0,TT2=0;
	for(int i=1;i<=n;i++) TT+=a[i]+a[i-1];
	TT/=2;
	for(int i=1;i<m;i++) TT2+=(bao[i].y+bao[i-1].y)*(bao[i].x-bao[i-1].x);
	TT2/=2;
	cout << fixed << setprecision(1) << TT-TT2;
//	for(int i=0;i<m;i++) cout << bao[i].x <<" " << bao[i].y  << "\n";
	return 0;
}
