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
//poin ans[100005];
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
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i].x >> a[i].y;
	int first=find();
	cout << first;
	return 0;
}
