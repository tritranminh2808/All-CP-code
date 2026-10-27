#include <bits/stdc++.h>
using namespace std;
int sech[100005];
signed main(){
	sech[1]=1;
	unordered_map<int,int> mp;
	mp[1]=1;
	for(int i=2;i<=100000;i++) {
		sech[i]=sech[i-1]+i;
		mp[sech[i]]=i;
	}
	int n; cin >> n;
	vector <int> a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	int cnt=0,sol=0,last=0;
	for(int i=1;i<=n;i++){
		if(mp[a[i]]!=0){
			if(a[i]>=last){
				cnt++;
				sol=max(sol,cnt);
				last=a[i];
			}
		}
		else{
			last=0;
			cnt=0;
		}
	}
	cout << sol;
}
