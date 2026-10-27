#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll kc[200005];
int a[200005];
struct gg{
	int i,j,c;
	bool chk(){
		return a[j]-a[i]<=c;
	}
};
gg e[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,A,B;
	cin >> n >> m >> A >> B;
//	for(int i=1;i<=n;++i) kc[i]=1e18;
	for(int i=1;i<=m;i++){
		int a,b,C;
		cin >> a >> b >> C;
		e[i].i=a;
		e[i].j=b;
		e[i].c=C;
	}
	for(int i=1;i<=n;++i) a[i]=A;
	int lcnt=0;
	while(1){
		bool cc=1;
		for(int k=1;k<=m;k++){
			if(!e[k].chk()){
				a[e[k].i]=a[e[k].j]-e[k].c;
				cc=0;
				if(a[e[k].i]>B){
					cout << "NO";
					return 0;
				}
			}
		}
		if(lcnt==n&&!cc) {
			cout << "NO";
			return 0;
		}
		if(cc) break;
	}
	cout << "YES\n";
	for(int i=1;i<=n;i++) cout << a[i] << ' ';
}

