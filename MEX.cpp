#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int a[p],n;
int main()
{
	cin >> n;
	unordered_map<int,bool> mp;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		mp[a[i]]=1;
	}
	int i=0;
	while(1){
		if(mp[i]==0){
			cout << i ;return 0;
		}
		++i;
	}
	return 0;
}
