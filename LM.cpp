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
signed main() {
	freopen("lm.inp","r",stdin);
	freopen("lm.out","w",stdout);
    
    string ss;
    cin >> n ;
    cin >> ss;
    
    for(auto i : ss) s.push_back(i-'0');
    sort (s.begin(),s.end());
    for(int i=0;i<1000006;i++) f[i].last=-1;
	bfs(); 
	if(f[0].last==-1){
		cout << 0;
		return 0;
	}
	deque <int> res;
	int i=0;
	do{
		int d=f[i].last;
		res.push_front(d);
		i=f[i].gene;
	}while(i!=0);
	for(int d : res) cout << d;
    return 0;
}

