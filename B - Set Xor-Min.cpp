#include<bits/stdc++.h>
using namespace std;

const int N=15000005,B=30;
int t[N][2],cnt[N],id=0;
unordered_map<int, int > mp;
void add(int x,int v){
    int p=0;
    for(int i=B-1;i>=0;--i){
        int b=(x>>i)&1;
        if(!t[p][b])t[p][b]=++id;
        p=t[p][b];
        cnt[p]+=v;
    }
}

int qry(int x){
    int p=0,r=0;
    for(int i=B-1;i>=0;--i){
        int b=(x>>i)&1;
        if(t[p][b]&&cnt[t[p][b]])p=t[p][b];
        else p=t[p][b^1],r|=(1<<i);
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q,o,x;
    cin>>q;
    while(q--){
        cin>>o>>x;
        if(o==0&&!mp[x])add(x,1),mp[x]=1;
        if(o==1&&mp[x])add(x,-1),mp[x]=0;
        if(o==2)cout<<qry(x)<<'\n';
    }
}

