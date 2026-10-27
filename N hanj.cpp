#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
vector <int> st[1005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			cin >> a[i][j];
			if(a[i][j])st[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||!a[i][j]) continue;
			for(auto k: st[j]){
				if(a[k][i]){
					cout << i << " " << j << " " << k;
					return 0;
				}
			}
		}
	}
	cout << "-1 -1 -1";
//	cok(1);
	return 0;
}
