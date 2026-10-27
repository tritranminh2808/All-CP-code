#include <bits/stdc++.h>
#define int long long
using namespace std;
int mua[10005],mub[10005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector <int> v;
	while(n!=0){
		v.push_back(n%3);
		n/=3;
	}
	vector <int> a,b;
	int gh=v.size();
	for(int i=0;i<v.size();i++) mua[i]=v[i];
	for(int i=0;i<=1004;i++){
		if(mua[i]==0) continue;
		if(mua[i]==1) a.push_back(pow(3,i));
		else{
			b.push_back(pow(3,i));
			for(int j=i+1;j<=1000;j++){
				mua[j-1]=0;
				mua[j]++;
				if(mua[j]==3) mua[j]=0;
				if(mua[j]==1) break;
				else if(mua[j]==2)b.push_back(pow(3,j));
			}
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(auto i : a) cout << i << " ";
	if(!b.empty()){
		cout << "\n";
		for(auto i:b) cout << i << " ";
	}
	return 0;
}
