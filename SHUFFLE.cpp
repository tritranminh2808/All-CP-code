#include <bits/stdc++.h>
using namespace std;
struct tri{
	int a,b;	
};
tri pl[1000005];
int main() {
	freopen("shuffle.inp","r",stdin);
	freopen("shuffle.out","w",stdout);
    int n, m;
    cin >> n;
    if(n==1) {
    	cout << 1;return 0;
	}

	cin >> m;
    for(int i=1;i<=n;i++){
    	pl[i].a=i-1;
    	pl[i].b=i+1;
	}
	pl[1].a=0;
	pl[0].b=1;
	pl[n].b=n+1;
	pl[n+1].a=n;
	int dau=1;
    while (m--) {
    	int l,r;
        cin >> l >> r;
        if(l==dau) {
        	if(pl[l].b!=r) dau=pl[l].b;
		}
        else if(r==dau) dau=l;
        pl[pl[l].a].b=pl[l].b;
        pl[pl[l].b].a=pl[l].a;
        pl[l].a=pl[r].a;
        pl[l].b=r;
        
        pl[pl[r].a].b = l;
		pl[r].a = l;
    }
  //  cout << dau << "\n";
	int z=dau;
	for(int i=0;i<n;i++)
	{
		cout << z << " ";
		z = pl[z].b;
	}
    return 0;
}

