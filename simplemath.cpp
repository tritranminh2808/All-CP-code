#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt [1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	for(int i=0;i<s.length();++i){
		if(s[i]=='U'||s[i]=='E'||s[i]=='A'||s[i]=='O'||s[i]=='I'||s[i]=='Y'){
			if(i==0)cnt[i]=1;
			else cnt[i]=cnt[i-1]+1;
		}
		else {
			if(i==0)cnt[i]=0;
			else cnt[i]=cnt[i-1];
		}
	}
	long double sol=0;
	for(int i=0;i<s.length();++i){
		for(int j=0;j<=i;j++){
			int k;
			if(j==0) k=0;
			else k=cnt[j-1];
			sol+=(long double) (cnt[i]-cnt[j-1])/(i-j+1);
		}
		
	}
	cout << fixed << setprecision(6) << sol ;
	return 0;
}
