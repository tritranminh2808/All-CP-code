#include <bits/stdc++.h>
#define int long long
using namespace std;

const int p=1e5+5;
vector < pair < int, int > > v(p);
int n;
bool check(int a,int k){
	int i=0;
	while(i<n)
	{
		k-=((v[i].second-v[i].first)/a)+1;
		i++;
	}
	if(k<=0) return true;
	return false;
}
signed main(){
	int k; cin >> k >> n;
	int maxn=-1;
	for(int i=0;i<n;i++){
		int a,b; cin >> a >> b;
		v.push_back({a,b});
		maxn=max(maxn,b);
	}
	int l=1,r=maxn;
	int mid=(r+l)/2;
	while(l!=r){
		mid=(r+l)/2;
		if(check(mid,k)!=true) r=mid-1;
		else l=mid+1;
		//cout << mid << l << r << endl;
	}
	cout << mid;
}
