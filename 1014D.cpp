#include <bits/stdc++.h>
#define int long long
using namespace std;
//char sol[1000005];
char lay(char a,char b){
	if(a=='L'&&b=='I') return 'T';
	if(a=='L'&&b=='T') return 'I';
	if(a=='I'&&b=='T') return 'L';
	if(a=='I'&&b=='L') return 'T';
	if(a=='T'&&b=='L') return 'I';
	if(a=='T'&&b=='I') return 'L';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
    	int n; cin>> n;
    	string s; cin >> s;
    	int cl=0,ci=0,ct=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]=='L') cl++;
    		else if(s[i]=='T') ct++;
    		else ci++;
		}
		int chk=ci+cl+ct;
		if(chk==ci||chk==cl||chk==ct) cout << -1 << "\n";
		else{
			int sech=max({ci,ct,cl});
			while(3*sech-n>2*n)sech++;
			int pi=sech-ci,pt=sech-ct,pl=sech-cl;
			vector <int> sol;
			for(int j=0;j<2*n;j++){
				if(pl==0&&pt==0&&pi==0) break;
				bool cc=0;
				for(int i=0;i<n;i++){
					if(s[i]!=s[i+1]){
						char loz=lay(s[i],s[i+1]);
						if((loz=='L'&&pl>0)||(loz=='T'&&pt>0)||(loz=='I'&&pi>0)){
							s.insert(s.begin()+i+1,loz);
							if(loz=='L') pl--;
							if(loz=='I') pi--;
							if(loz=='T') pt--;
							sol.push_back(i+1);
							cc=true;
							break;
						} 
					}
				}
				if(!cc) break;
			}
			if(pi==0&&pt==0&&pl==0) {
				cout << sol.size() << "\n";
				for(auto i : sol) cout <<i << "\n";
			}
			else cout << -1 << "\n";
		}
	}
    return 0;
}
 
