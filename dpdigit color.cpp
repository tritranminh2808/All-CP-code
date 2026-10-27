#include <bits/stdc++.h>
//#define int ll
//using ll=unsigned long long;
using namespace std;
int n,m;
//int f[200][200][10];
int a[6][11];
string s;
bool check(int mask, int i){
	for(int r=0;r<4;r++){
		if(a[r][i]&&(mask>>i)&1==0) return false;
	}
	return true;
}
int f[55][2][2][2][2][2];
int backtrack(int id,int h[5]){
	if(id>10) return 1;
	int &cnt=f[id][h[0]][h[1]][h[2]][h[3]][h[4]];
	if(cnt!=-1) return cnt;
	cnt=0;
	for(int mask=0;mask<=31;mask++){
		if(check(mask,id)) {
			int h2[5];
			for(int i=0;i<4;i++) h[i]=0;
			for(int j=0;j<4;j++){
				if(a[j][id]&&(mask>>j)&1==0) continue;
				for(int r=0;r<4;r++){
					if((mask>>j)&1==0)  h2[r]=h[r]+1;
					else h2[r]=0;
				}
				
			}
			cnt+=backtrack(id+1,h2);
		}
	}
	return cnt;
}
int S[5];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>> n;
	for(int i=1;i<=5;i++){
		string s; cin >> s;
		 for(int j=0;j<10;j++) a[i][j+1]=s[i]-'0';
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=5;j++) if(!a[j][i]) S[i] |= 1<<j;
	}
	cout << backtrack(n,S)-backtrack(n-1,S);
	
}
