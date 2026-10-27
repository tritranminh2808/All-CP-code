#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll m=1e9+7;
int n;
vector < vector <int> > mul( vector <vector <int> > a, vector <vector <int> > b, int n){
	vector <vector <int> >  c(n,vector <int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=m;
            }
        }
    }
    return c;
}
vector < vector <int> > bp(vector < vector <int> > a, int p) {
    if (p== 1) {
        return a;
    }
    vector < vector <int> > tmp = bp(a, p/ 2);
    tmp = mul(tmp,tmp,n);
    if (p% 2 == 1) {
        tmp=mul(tmp,a,n);
    }
    return tmp;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int d;
    vector <int> base(n);
    for(int i=0;i<n;i++) cin >> base[i];
    cin >> d;
	vector < vector <int> > matran(n,vector <int> (n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<=j )matran[i][j]=1;
			else matran[i][j]=0;
		}
	}
	vector <vector <int> > r=bp(matran,d);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cout << r[i][j] << " ";
		cout << endl;
	}
    return 0;
}
 
