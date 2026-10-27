#include <bits/stdc++.h>
#define int ll
//using ll=unsigned long long;
using namespace std;
int n,m;
int f[200][200][10];
string s;
int cok(int id,int sum,int pre){
	if(id==n){
		if(sum==m) return 1;
		return 0;
	}
	int &a=f[id][sum][pre];
	if(a!=-1) return a;
	a=0;
	for(int i=0;i<=9;i++){
		if(sum+i<=m&&pre*10+i!=13) a+=cok(id+1,sum+i,i);
	}
	return a;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		memset(f,-1,sizeof(f));
		int s1=cok(0,0,0);
		cout << s1 << "\n";
	}
	return 0;
}
