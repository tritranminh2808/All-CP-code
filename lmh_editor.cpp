#include <bits/stdc++.h>
using namespace std;
int f[1000005],f1[1000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("input.inp","r",stdin);
//	freopen("output.out","w",stdout);
	int t; cin >> t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(f1,0,sizeof(f1));
		string s; cin >> s;
		f[0]=0;
		int n=s.length();
		for(int i=1;i<n;++i){
			int j=f[i-1];
			while(j>0&&s[i]!=s[j]) j=f[j-1];
			if(s[i]==s[j]) j++;
			f[i]=j;
		}
//		for(int i=0;i<n;i++) cout << f[i] << " ";
//		cout << "\n";
		int id=n,cnt=0;
		while(id>0){
//			cout << id << "\n";;
			if(f[id]==0) id--;
			else {
				int x=f[id];
				while(2*x>id+1) x=f[x-1];
				id-=x;
			}
			cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}
