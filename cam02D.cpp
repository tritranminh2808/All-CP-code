#include <bits/stdc++.h>
#define int long long
using namespace std;
char sol[1000005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    map<char,int> mp;
	for(auto i : s) mp[i]++;
	int ind=0;
	char mid='!';
	for(auto i:mp){
		while(i.second>1){
			sol[ind]=i.first;
			sol[1000000-ind]=i.first;
			i.second-=2;
			ind++;
		}
		if(i.second==1&&mid=='!') mid=i.first; 
	}
	sol[1000000/2]=mid;
	for(int i=0;i<=1000000;i++){
		if(sol[i]>='a'&&sol[i]<='z') cout << sol[i];
	}
    return 0;
}
 
