#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> adj[26];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
    cin>> a >> b;
    int n=a.length(),m=b.length();
    a='!'+a;
    b='!'+b;
    for(int i=1;i<=m;i++) adj[b[i]-'a'].push_back(i);
    int len=n-m+1,sol=0;
    for(int i=1;i<=n;i++){
        int l=max((int)0,i-len+1);
        int r=min(i,m);
        sol+=upper_bound(adj[a[i]-'a'].begin(),adj[a[i]-'a'].end(),r)-lower_bound(adj[a[i]-'a'].begin(),adj[a[i]-'a'].end(),l);
    }
    cout << sol;
}
