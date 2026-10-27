#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int,int > a, pair <int, int > b){
	if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> v(m);
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            v[i]={x/100,x};
        }
        sort(v.begin(), v.end(),cmp);
        vector<int> r(m);
        for(int i=0;i<m;i++) r[i]=v[i].second;
        int p=m/2,memay = n;
        vector<int> low(n),high(n),par(n);
        int ind=0;
        for(int i=0;i<p&& memay>0;i++){
            int l=r[i],h=r[m-i-1];
            if(memay>=2){
                low[ind]=l;
				high[ind]=h;
				par[ind]=0;
				ind++;
                low[ind]=l; 
				high[ind]=h; 
				par[ind]=1; 
				ind++;
                memay-=2;
            } else if(memay==1){
                low[ind]=l; 
				high[ind]=h; 
				par[ind]=0; 
				ind++;
                memay--;
            }
        }
        if(memay>0){
            low[ind]=r[p]; 
			high[ind]=r[p]; 
			par[ind]=0;
            memay--;
        }
        for(int i=0;i<n;i++){
            if(!par[i]) cout << low[i] << " " << high[i] << " " << low[i] << " " << high[i] << " " << low[i] << " " << high[i] << "\n";
            else cout << high[i] << " " << low[i] << " " << high[i] << " " << low[i] << " " << high[i] << " " << low[i] << "\n";

        }
    }
    return 0;
}

