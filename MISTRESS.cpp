#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b;
int f[20][2][1<<12];
const int mod=1e9+7;
int backtrack(int id, bool l, int mask,int val){
    if(id==a.size()){
        int k=__builtin_popcount(mask);
        k--;
        if(val%k==0) {
            // cout << val << " " << k << '\n';
            return val%mod;
        }
        return 0;
    }
    int &as=f[id][l][mask];
    if(as!=-1) return as;
    as=0;
    for(int i=0;i<10;i++){
        if(l||i<=a[id]-'0') as+=backtrack(id+1,l||i<a[id]-'0',mask|(1<<i),(val*10+i)%mod);
    }
    return as;
}
string iii(string s){
	int ss=0;
	for(auto i:s){
		ss*=10;
		ss+=i-'0';
	}
	string tt;
	ss--;
//	cout << ss;
	do{
		tt+='0'+ss%10;
		ss/=10;
	}
	while(ss!=0);
	reverse(tt.begin(),tt.end());
	return tt;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> b >> a;
    memset(f,-1,sizeof(f));
    int s1=backtrack(0,0,0,0);
    a=iii(b);
    memset(f,-1,sizeof(f));
    int s2=backtrack(0,0,0,0);
    cout << s1-s2;
}