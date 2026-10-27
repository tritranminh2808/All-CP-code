#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> par,hei;
    dsu(int n):par(n+1),hei(n+1,0){
        for(int i=1;i<=n;i++)par[i]=i;
    }
    int finds(int u){
        return par[u]==u?u:(par[u]=finds(par[u]));
    }
    bool join(int u,int v){
        u=finds(u);v=finds(v);
        if(u==v)return false;
        if(hei[u]==hei[v])hei[u]++;
        if(hei[u]>hei[v])par[v]=u;
        else par[u]=v;
        return true;
    }
    void reset(){
        for(size_t i=1;i<par.size();i++){
            par[i]=i;
            hei[i]=0;
        }
    }
};

struct edge{int u,v,id;};

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<int> cost_a(n),cost_b(n);
        for(int i=1;i<n;i++)cin>>cost_a[i];
        for(int i=1;i<n;i++)cin>>cost_b[i];
        vector<edge> A,B;
        for(int i=1;i<=m;i++){
            int u,v,t;
            cin>>u>>v>>t;
            if(t==1)A.push_back({u,v,i});
            else B.push_back({u,v,i});
        }
        dsu uf(n);
        int maxA=0;
        for(auto&e:A)
            if(uf.join(e.u,e.v))maxA++;
        uf.reset();
        int maxB=0;
        for(auto&e:B)
            if(uf.join(e.u,e.v))maxB++;
        int minA=(n-1)-maxB;
        int bestCost=INT_MAX,k=-1;
        for(int x=minA;x<=maxA;x++){
            int y=n-1-x;
            int c=cost_a[x]+cost_b[y];
            if(c<bestCost){
                bestCost=c;
                k=x;
            }
        }
        bitset<100001> used;
        uf.reset();
        for(auto&e:B)uf.join(e.u,e.v);
        for(auto&e:A)if(uf.join(e.u,e.v))used[e.id]=1;
        uf.reset();
        int rem=k;
        for(auto&e:A)if(used[e.id]&&rem>0){
            uf.join(e.u,e.v);
            rem--;
        }
        for(auto&e:A)if(rem>0&&uf.join(e.u,e.v)){
            used[e.id]=1;
            rem--;
        }
        for(auto&e:B)if(uf.join(e.u,e.v))used[e.id]=1;
        for(int i=1;i<=m;i++)
            if(used[i])cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}