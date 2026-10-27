#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		vector <int> v(5);
		int j=0;
		for(int i=0;i<4;i++) {
			int x; cin >> x;
			if(i==2) j++; 
			v[j]=x;
			j++;
		}
		int res=-234213213;
		for(int k=-100;k<=100;k++){
			int cnt=0;
			v[2]=k;
			for(int i=0;i<3;i++){
				if(v[i]+v[i+1]==v[i+2]) cnt++;
			}
			res=max(res,cnt);
		}
		cout << res << "\n";
	}
	return 0;
}
