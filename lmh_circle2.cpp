#include <bits/stdc++.h>
using namespace std;
int n; 
int phi[1000005],deg[1000005];
vector <pair <int, int > > day;
bool vst[1000005];;
void cook(){
	for(int i=1;i<=n;i++){
		if(vst[i]||deg[i]>0) continue;
		int start=i,ed=0;
		int cur=i;
		while(!vst[cur]){
			vst[cur]=1;
			ed=cur;
			cur=phi[cur];
		}
		day.push_back({start,ed});
	}
	for(int i=1;i<=n;i++){
		if(vst[i]) continue;
		int start=i,ed=0;
		int cur=i;
		while(!vst[cur]){
			vst[cur]=1;
			ed=cur;
			cur=phi[cur];
		}
		day.push_back({start,ed});
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		int u; cin >> u;
		phi[i]=u;
		deg[u]++;	
	}
	cook();
	cout << day.size() << "\n";
	for(int i=0;i<day.size();i++){
        int j=(i+1)%day.size();
        cout << day[i].second << " " << day[j].first << "\n";
    }
	return 0;
}

