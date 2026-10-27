#include <bits/stdc++.h>
using namespace std;
struct pl{
    int tx,ty,px,py;
};
pl a[100005];
bool check(pl x, pl y){
    int wx=abs(x.ty-x.py)*2,lx=abs(x.tx-x.px)*2,wy=abs(y.ty-y.py)*2,ly=abs(y.tx-y.px)*2;

    int trai1=x.tx-lx/2,y1=x.ty-wx/2;
    int phai1=x.tx+lx/2;
    // cout << wx << " " << lx;
    int trai2=y.tx-ly/2,y2=y.ty-wy/2;
    int phai2=y.tx+ly/2;
    if(trai1>=phai2||trai2>=phai2) return false;
    if(phai1<=trai2||phai2<=trai1) return false;
    if(y1<y2){
        if(wx>y2-y1) return true;
        else return false;
    }
    if(y1>y2){
        if(wy>y1-y2) return true;
        else return false;
    }
    if(y1==y2) return true;
    return false;
}
vector <int> adj[1005];
long long kc[1005];
void dijkstra(int u){
    priority_queue<pair <int, int > , vector <pair <int, int > > , greater <pair <int ,int> > > pq;
    kc[u]=0;
    pq.push({0,u});
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        if(kc[p.second]<p.first) continue;
        for(auto i:adj[p.second]){
            if(p.first+1<kc[i]){
                kc[i]=p.first+1;
                pq.push({kc[i],i});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i].tx >> a[i].ty >> a[i].px >> a[i].py;
    // if(check(a[1],a[2])) cout << "ngu";
    // return 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) {
            if(check(a[i],a[j])) {
                // cout << i << " " << j << "\n";
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++) kc[i]=1e18;
    dijkstra(1);
    if(kc[n]!=1e18)cout << kc[n];
    else cout << -1;
    return 0;
}