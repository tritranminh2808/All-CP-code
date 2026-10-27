#include <bits/stdc++.h>
#define int long long
using namespace std;

int snt[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
const int maxn=1e18;
map<int, int> res,tmp;
void sech(int i, int x, int somu, int sigmax){
	tmp[x]=sigmax; 
	if(i==15) return;
	int y=x;
	for(int e=0;e<=somu;++e)
	{
		if(y<=maxn/snt[i])
		{
			if(e>0)y*=snt[i];
			sech(i+1,y,e,sigmax*(e+1));
		}
		else break;
	}
}
signed main(){
	freopen("NL.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sech(0,1,60,1);
	int cur=0;
	for(auto i:tmp){
		if(i.second>cur){
			res.insert(i);
			cur=i.second;
		}
	} 
	cout << "int x1[" << res.size()+1 << "]={";
	for(auto i : res) cout << i.first << "," ;
	cout << "};";
	cout << endl;
	cout << "int x2[" << res.size()+1 << "]={";
	for(auto i : res) cout << i.second << "," ;
	cout << "};";
	return 0;
}

