#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n=s.length();
		vector <int> upin(n+1,0),ipin(n+1,0);
		for(int i=0;i<s.length();i++){
			if(s[i]=='U') {
				upin[i+1]=1;
				ipin[i+1]=-2;
			}
			else {
				upin[i+1]=-2;
				ipin[i+1]=1;
			}
			upin[i+1]+=upin[i];
			ipin[i+1]+=ipin[i];
		}
//		for(int i=1;i<=s.length();i++) cout << ipin[i] << " ";
		unordered_map<int,int> mp1, mp2;
		mp1[0]=0;
		mp2[0]=0;
		bool chk=0;
		for(int i=1;i<=n;i++){
			if(mp1.count(upin[i])){
				cout << "Yes " << mp1[upin[i]]+1 << " " << i << "\n";
				chk=1;
				break;
			}
			else mp1[upin[i]]=i;
			if(mp2.count(ipin[i])){
				cout << "Yes " << mp2[ipin[i]]+1 << " " << i << "\n";
				chk=1;
				break;
			}
			else mp2[ipin[i]]=i;
		}
		if(!chk) cout << "No\n";
	}
	return 0;
}
