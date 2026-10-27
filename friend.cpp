#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
vector <pair < int, int > >   adj[100005];
int kc[100005],kc2[100005];
vector < int > t(100005,-1);
void dijkstra(int u)
{
	kc[u]=0;
	pq.push({kc[u],u});
	while(!pq.empty()){
		pair <int, int > p=pq.top();
		pq.pop();
		if(kc[p.second]<p.first) continue;
		for(auto i: adj[p.second]){
			if(p.first+i.second<kc[i.first]){
				kc[i.first]=p.first+i.second;
				pq.push({kc[i.first],i.first});
				t[i.first]=p.second;
			}
		}
	}
}
void dijkstra2(int u)
{
	kc2[u]=0;
	pq.push({kc2[u],u});
	while(!pq.empty()){
		pair <int, int> p=pq.top();
		pq.pop();
		if(kc2[p.second]<p.first) continue;
		for(auto i: adj[p.second]){
			if(p.first+i.second<kc2[i.first]){
				kc2[i.first]=p.first+i.second;
				pq.push({kc2[i.first],i.first});
				t[i.first]=p.second;
			}
		}
	}
}

vector<int> trace(int S, int u) {
    if (u != S&&t[u]==-1) return vector<int>(1, -1); 
    vector<int> path;
    while (u != -1) { 
        path.push_back(u);
        u=t[u];
    }
    reverse(path.begin(), path.end()); 
    return path;
}
bool vst[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<pair <int, int > , int> mp;
	int n,m,sa,sb,ha,hb;
	cin >> n >> m;
	cin >> sa >> sb >> ha >> hb;
	for(int i=1;i<=n;++i) {
		kc[i]=1e16;
		kc2[i]=1e16;
	}
	for(int i=1;i<=m;i++){
		int a,b,c; cin >>a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dijkstra(sa);
	vector <int> an=trace(sa,sb);
	for(int i=0;i<=100000;i++) t[i]=-1;
	dijkstra2(ha);
	vector <int> binh=trace(ha,hb);
	if(kc[sb]==1e16||kc2[hb]==1e16){
		cout << "NO";
		return 0;
	}
	for(auto i:binh) vst[i]=1;
	int gap=-1,lengap=-1;
	for(auto i:an){
		if(vst[i]&&kc2[i]==kc[i]) {
			gap=i;
			lengap=kc[i];
			break;
		}
	}
	if(gap==-1){
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	cout << kc[sb] << "\n"<< kc2[hb] << "\n" << gap << "\n" << lengap; 
//	for(int i=1;i<=n;++i) kc2[i]=1e16;
	
	return 0;
}

