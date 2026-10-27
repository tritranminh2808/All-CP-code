#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
vector <pair < int, int > >   adj[1000005];
int kc[1000005];
int n;
int dijkstra()
{
	for(int i=1;i<=9;i++){
		int r=i%n;
		if(i<kc[r]){
			kc[r]=i;
			pq.push({i,r});
		}
	}	
	while(!pq.empty()){
		pair <int, int > p=pq.top();
		pq.pop();
		if(kc[p.second]!=p.first) continue;
		if(p.second==0) return p.first;
		for(int i=0;i<=9;i++){
			int mod=(p.second*10+i)%n,val=p.first+i;
			if(val<kc[mod]){
				kc[mod]=val;
				pq.push({kc[mod],mod});
			}
		}
	}
	return -1;
}
signed main(){
	for(int i=0;i<=1000005;++i) kc[i]=1e18;
	cin >> n;
	cout << dijkstra();
}
