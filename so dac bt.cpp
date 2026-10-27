#include <bits/stdc++.h>
#define int long long
using namespace std;
int k;
string p,s;
bool snt[1000];
void txl(){
	snt[0]=1;
	snt[1]=1;
	for(int i=2;i*i<=999;i++){
		if(snt[i]) continue;
		for(int j=i;j*i<=999;j++) snt[i*j]=1;
	}
}
//const int mod=1e9+7;
int f[18][136][136][4];
int backtrack(int id,int sumx,int sumy,int nho){
//	cout << p << "\n";
	if(id==s.size()){
		if(!snt[sumx]&&!snt[sumy]&&nho==0) return 1;
		return 0;
	}
	int &a=f[id][sumx][sumy][nho];
	if(a!=-1) return a;
	a=0;
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;++j){
			if((i+2*j+nho)%10==s[id]-'0') a+=backtrack(id+1,sumx+i,sumy+j,(i+2*j+nho)/10);
		}
	}
	return a;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	txl();
	cin >> s;
	reverse(s.begin(),s.end());
//	cout << s << "\n";
	memset(f,-1,sizeof(f));
	cout << backtrack(0,0,0,0);
//	cout << sol;
	return 0;
}
