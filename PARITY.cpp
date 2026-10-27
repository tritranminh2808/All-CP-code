#include<bits/stdc++.h>
using namespace std;
int pre[100005];
int main(){
	int n; cin >> n;
	vector <int> a(n+1);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]%2==0) a[i]=1;
		else a[i]=-1;
	}
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	unordered_map<int,int> mp;
	mp[0]=1;
	int sol=0;
	for(int i=1;i<=n;i++){
		if(mp[pre[i]]) sol+=mp[pre[i]];
		mp[pre[i]]++;
	}
	cout << sol;
	return 0;
}
