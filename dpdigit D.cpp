#include <bits/stdc++.h>
//#define int long long
using namespace std;
using ll=long long;
ll s,k;
//const int mod=1e9+7;
ll f[66][2][66][2];
string bit;
ll backtrack(int id,bool l,ll cnt,bool start){
//	cout << p << "\n";
	if(id==bit.size()){
		if(cnt==k&&start) return 1;
		return 0;
	}
	ll &a=f[id][l][cnt][start];
	if(a!=-1) return a;
	a=0;
	int lm=l?1:bit[id]-'0';
	for(int i=0;i<=lm;i++) {
		bool ch=start||(i==1);
		a+=backtrack(id+1,l||i<lm,cnt+(ch&&i==0),ch);
	}
	return a;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>> s){
		cin >> k;
		memset(f,-1,sizeof(f));
		bit.clear();
		for(int i=63;i>=0;--i){
			if(bit.empty()&&!((s>>i)&1)) continue;
			if((s>>i)&1) bit.push_back('1');
			else bit.push_back('0');
		}
		if(bit.empty()) bit="0";
		cout << backtrack(0,0,0,0) << "\n";
	}
	return 0;
}
