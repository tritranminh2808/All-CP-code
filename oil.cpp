#include <bits/stdc++.h>
using namespace std;
int a[305][305];
unordered_map<int,vector <pair<int, int > >  > mp;
int main(){
	int n,m,S; cin >> n >> m>>S;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			int tong=a[i][j]+a[i+1][j];
			mp[tong].push_back({i,j});
		}
	}
	for(int i=0;i<=S/2;i++){
		int t1=i,t2=S-i;
		for(auto i :mp[t1]){
			for(auto j: mp[t2]){
				if(i.first==j.first&&i.second!=j.second){
					if(i.first > j.first) cout << j.first << " " << j.second << " " << i.first+1 << " " << i.second ;
					else cout << i.first << " " << i.second << " " << j.first+1 << " " << j.second ;
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}
