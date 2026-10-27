#include <bits/stdc++.h>
#define int long long
using namespace std;
struct vecto{
	int x,y;
};
using poin=vecto;
poin A;
poin a[100005];
int n;
poin ans[100005];
int find(){
	int f;
	int curx=1e18,cury=1e18;
	for(int i=0;i<n;i++){
		if(a[i].y<cury){
			cury=a[i].y;
			curx=a[i].x;
			f=i;
		}
		else if(a[i].y==cury){
			if(a[i].x<curx){
				cury=a[i].y;
				curx=a[i].x;
				f=i;
			}
		}
	}
	return f;
}
int nhancheo(poin A, poin B){
	return A.x*B.y-A.y*B.x;
}
int cal(poin A){
	return A.x*A.x+A.y*A.y;
}
bool cmp(poin A, poin B){
	poin p,l;
	p.x=A.x-a[0].x;
	p.y=A.y-a[0].y;
	l.x=B.x-a[0].x;
	l.y=B.y-a[0].y;
	int k=nhancheo(p,l);
	return k>0||k==0 && cal(p) < cal(l);
}
bool CCW(const poin& D, const poin& E, const poin& F){
	poin p,l;
	p.x=E.x-D.x;
	p.y=E.y-D.y;
	l.x=F.x-E.x;
	l.y=F.y-E.y;
	return nhancheo(p,l) >0;
}
int m=0;
void dientich(){
	ans[m]=ans[0];
	int s=0;
	for(int i=0;i<m;i++){
		s+=nhancheo(ans[i],ans[i+1]);
	}
	cout << s/2 << "." << s%2*5 << "\n";
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i].x >> a[i].y;
	int first=find();
//	cout << a[first].x << " " << a[first].y;
	swap(a[0],a[first]);
	sort(a+1,a+n,cmp);
	// for(int i=0;i<n;i++) cout << a[i].x << " " << a[i].y << endl;
	for(int i=0;i<n;i++){
		while(m>=2&&!CCW(ans[m-2],ans[m-1],a[i])) --m;
		ans[m++]=a[i];
	}
	cout << m << "\n";
	dientich();
	for(int i=0;i<m;i++) cout << ans[i].x << " " << ans[i].y << "\n";
	return 0;
}
