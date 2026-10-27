#include <bits/stdc++.h>
#define int long long
using namespace std;
bool snt[1000005];
void sang(){
	for(int i=2;i*i<=1000005;i++){
		if(snt[i]) continue;
		for(int j=i;j*i<=1000005;j++) snt[i*j]=1;
	}
}
vector <int> ngto;
int cnt=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	sang();
	snt[1]=1;
	for(int i=1;i<=1000005;i++) if(!snt[i]) ngto.push_back(i);
	vector <int> v;
	long long n;
	cin >> n;
	int sech=n;
	for(auto c:ngto){
		if(c*c>sech) break;
		for(auto a:ngto){
			if(a==c) continue;
			if(a*a*c*c>sech||a>c) break;
			for(auto b:ngto){
				if(b==a||b==c|b<a) continue;
				if(b*a*a*c*c>sech||b>c) break;
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
