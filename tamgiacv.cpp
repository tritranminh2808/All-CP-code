#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("TAMGIACV.INP","r",stdin);
	freopen("TAMGIACV.OUT","w",stdout);
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	int ABx = x2 - x1, ABy = y2 - y1;
	int CBx = x2 - x3, CBy = y2 - y3;
	if(ABx*CBx + ABy*CBy!=0){
		cout<<"0";
		return 0;
	}
	int Dx= x3 - ABx, Dy= y3 - ABy;
	cout<< Dx<<" "<<Dy;
}
