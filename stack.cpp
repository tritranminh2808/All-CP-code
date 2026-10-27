#include <bits/stdc++.h>
#define int long long
#define w first
#define c second
using namespace std;
int f[1000005];
bool cmp(pair<int, int > a,pair <int, int > b){
	return a.first+a.second < b.first+b.second;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<=1000000;i++) f[i]=100000000000008;
    int n; 
    cin >> n;
    vector<pair<int, int >> a(n);
    for(int i=0;i<n; i++)cin >> a[i].w;
     for(int i=0;i<n; i++)cin >> a[i].c;
    sort(a.begin(), a.end(),cmp);
    f[0]=0;
    for(int i=0;i<n;i++){
    	for(int j=n;j>=1;j--){
    		if(a[i].c>=f[j-1]) f[j]=min(f[j],f[j-1]+a[i].w);
		}
	}
	int sol=0;
	for(int i=0;i<=n;i++) if(f[i]<100000000000008)sol=i;
	cout << sol;
    return 0;
}

