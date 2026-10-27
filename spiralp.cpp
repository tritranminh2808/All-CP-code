#include <bits/stdc++.h>
#define int long long
#define ii v[i].first
#define jj v[i].second
using namespace std;
vector <int> s;
int a[202][30002],ss[202][30002],n,m,dem[6000000+5],C[6000000+5],f[6000000+5];
void build(){
	for(int i=1;i<=m*n;i++)s.push_back(i);
    //sort(s.begin(),s.end());
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = m - 1;
    int dem = 1;
    int p=0; 
    while(h1 <= h2 && c1 <= c2){
        for(int i = c1; i <= c2; i++){a[h1][i] = s[p]; ++p;}
        if(p==s.size()) break;
        ++h1;
        for(int i = h1; i <= h2; i++){a[i][c2] = s[p]; ++p;}
        --c2;
        if(p==s.size()) break;
        for(int i = c2; i >= c1; i--){a[h2][i] = s[p]; ++p;}
        --h2;
        if(p==s.size()) break;
        for(int i = h2; i >= h1; i--){a[i][c1] = s[p]; ++p;}
        ++c1;
        if(p==s.size()) break;
    }
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
    cin >> n >> m>> k;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++) {
    		cin >> ss[i][j];
		}
	}
    build();
    vector < pair < int, int > > v(n*m+1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            v[a[i][j]].first=i;
            v[a[i][j]].second=j;
        }
    }
    for(int i=1;i<=n*m;++i) C[i]=ss[ii][jj];
    deque <int> dq;
    for(int i=1;i<=k;i++) {
    	dem[i]=(C[i]==1)?INT_MAX:0;
    	if(C[i]!=1)dq.push_back(i);
	}
    
	for(int i=k+1;i<=n*m;i++){
		if(C[i]==1) dem[i]=INT_MAX;
		else{
			while(!dq.empty()&&dem[dq.back()]>dem[i-1]) dq.pop_back();
			dq.push_back(i);
			if(dq.front()+k<=i)dq.pop_front();
			dem[i]=dem[dq.front ()]+1;
			//cout << dem [i] <<" " << i << endl;
		} 
	}
	if(dem[n*m]==INT_MAX) cout << -1 << " ";
	else cout << dem[n*m] << " ";
	for(int i=2;i<=k+1;i++){
		if(C[i]==0) f[1]++;
	}
	for(int i=2;i<=n*m-k-1;i++){
		f[i]=f[i-1];
		if(C[i]==0) f[i]--;
		if(C[i+k]==0) f[i]++;
	}
	for(int i=n*m-k;i<=n*m;i++) {
		f[i]=f[i-1];
		if(C[i]==0) f[i]--;
	}
	int maxn=-INT_MAX;
	for(int i=1;i<=n*m;i++)  maxn=max(maxn,f[i]);
	cout << maxn;
    return 0;
}
