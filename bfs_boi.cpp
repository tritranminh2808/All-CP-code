#include <bits/stdc++.h>
using namespace std;
struct kdl{
	int last;
	int gene;
	bool known;
};
kdl f[1000005];
vector <int> s;
vector <int > a,b;
int n;
void bfs(){
	for(int d: s){
		if(d!=0){
			int i=d%n;
			if(f[i].last==-1) {
				f[i]={d,0};
				a.push_back(i);
			}
		}
	}
	while(f[0].last==-1&&!a.empty()){
		b.clear();
		for(int i : a){
			for(int d : s){
				int j=(i*10+d)%n;
				if(f[j].last==-1){
					f[j]={d,i};
					b.push_back(j);
				}
			}
		}
		a.swap(b);
		
	}
}
bool sech[10];
signed main() {
	// freopen("lm.inp","r",stdin);
	// freopen("lm.out","w",stdout);
    
    int m;
    cin >> n >> m;
    
    for(int i=1;i<=m;i++){
        int x;cin >> x;
        sech[x]=1;
    }
	for(int i=0;i<=9;i++) if(!sech[i]) s.push_back(i);
    sort (s.begin(),s.end());
    for(int i=0;i<1000006;i++) f[i].last=-1;
	bfs(); 
	if(f[0].last==-1){
		cout << "IMPOSSIBLE";
		return 0;
	}
	deque <int> res;
	int i=0;
	do{
		int d=f[i].last;
		res.push_front(d);
		i=f[i].gene;
	}while(i!=0);
    if(res.size()<9){
        for(auto i:res) cout << i;
        return 0;
    }
	for(int i=0;i<3;i++) cout << res[i];
    cout <<"...";
    for(int i=res.size()-3;i<res.size();i++) cout << res[i];
    cout << "(" << res.size() << " digits)"; 
    return 0;
}

