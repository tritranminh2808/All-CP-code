#include <bits/stdc++.h>
using namespace std;
int main(){
	unordered_map<string , int> mp;
	int n; cin >> n;
	for(int i=0;i<n;i++){
		string s; cin >> s;
		mp[s]++;
	} 
	for(auto i: mp){
		if(i.second%2==1){
			cout << i.first;
			return 0;
		}
	}
	return 0;
}
