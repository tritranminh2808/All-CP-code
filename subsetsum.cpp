#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
int f[100005],b[100005],val[200005];
vector <int> pos[200005],a;
vector <int> sol;
void select(int v){
	if(!pos[v].empty()){
		sol.push_back(pos[v].back());
		pos[v].pop_back();
	}
	else {
		// if(v%2==1){
		// 	cout << "NO";
		// 	exit(0);
		// }
		select(v/2);
		select(v/2);
	}
}
int main(){
	// freopen("subsetsum.inp","r",stdin);
	// freopen("subsetsum.out","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> b[i];
		pos[b[i]].push_back(i);
		val[b[i]]++;
	}
	for(int i=1;i<=100000;i++){
		if(val[i]<3) continue;
		while(val[i]>2){
			val[i]-=2;
			val[2*i]++;
		}
	}
	a.push_back(-1);
	for(int i=1;i<=200000;i++){
		for(int j=1;j<=val[i];j++) a.push_back(i);
	}
	n=a.size()-1;
	// return 0;
	if(m>100000) {
		cout << "NO";
		return 0;
	}
	f[0]=0;
	for(int i=1;i<=m;i++){
		f[i]=n+1;
		for (int j = 1; j <= n; ++j)
        if (a[j] <= i && f[i - a[j]] < j) {
            f[i] = j; 
			break;
        }
	}
	if(f[m]==n+1) {
		cout << "NO"; return 0;
	}
	cout << "YES\n";
	
	while(m!=0){
	//	cout << m << " ";
		int i=f[m];
		select(a[i]);
		// sol.push_back(i);
		m-=a[i];
		
	}
//	cout << sol.size() << endl;
	sort(sol.begin(),sol.end());
	for(auto i:sol) cout << i << " ";
}
