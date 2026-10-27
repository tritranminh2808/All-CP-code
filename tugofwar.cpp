#include <bits/stdc++.h>
using namespace std;
int f[1000005],a[100005];
bool check[100005];
int main(){
	freopen("tugofwar.inp","r",stdin);
	freopen("tugofwar.out","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,m; cin >> n;
	int tong=0;
//	cout << tong;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		tong+=a[i];
	}
	f[0]=0;
	m=tong/2;
	for(int i=1;i<=m;i++){
		f[i]=n+1;
		for (int j = 1; j <= n; ++j)
        if (a[j] <= i && f[i - a[j]] < j)
        {
            f[i] = j; break;
        }
	}
//	cout << f[m];
	while(f[m]==n+1) m--;
	vector <int> sol;
	while(m!=0){
	//	cout << m << " ";
		int i=f[m];
		sol.push_back(i);
		m-=a[i];
	}
	cout << sol.size() <<" " << n-sol.size() <<  "\n";
	for(int i=sol.size()-1;i>=0;i--) {
		cout << sol[i] << " ";
		check[sol[i]]=1;
	}
	cout << "\n";
	for(int i=1;i<=n;i++) {
		if(check[i]==1) continue;
		cout << i << " ";
	}
}

