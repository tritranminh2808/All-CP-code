#include <bits/stdc++.h>
using namespace std;
struct tri{
	int a,b;	
};
tri pl[100005];
int main() {
//	freopen("shuffle.inp","r",stdin);
//	freopen("shuffle.out","w",stdout);
    int n, m, i, j;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	pl[i].a=i-1;
    	pl[i].b=i+1;
	}
	pl[0].a=n;
	pl[0].b=1;
	pl[1].a=0;
	pl[n].b=0;
	int dau=1;
    while (m--) {
    	int l,r;
        cin >> l >> r;
        if(l==dau) dau=pl[l].b;
        else if(r==dau) dau=l;
        pl[pl[l].a].b=pl[l].b;
        pl[pl[l].b].a=pl[l].a;
        pl[l].a=pl[r].a;
        pl[l].b=r;
        
        pl[pl[r].a].b = l;
		pl[r].a = l;
    }
    //cout << dau;
	int z=dau;
	for(int i=1;i<=n;i++) cout << pl[i].a<< " " << pl[i].b << "\n";
    return 0;
}

